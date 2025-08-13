-- File Name: Computer.vhd
-- Author: Tate Finley
-- Purpose: Representation of phases 1-2 of the project.

Library ieee;
use ieee.std_logic_1164.all;

entity Computer is 
	port( D:					IN STD_LOGIC_VECTOR(31 downto 0);
			address:			IN STD_LOGIC_VECTOR(7 downto 0);
			clock, reset, reg_reset: 	IN STD_LOGIC;
			wren: 			IN STD_LOGIC;
			Instr, ALU_o, dataMem: 				OUT STD_LOGIC_VECTOR(31 downto 0);
			Q: 				OUT STD_LOGIC_VECTOR(31 downto 0));
end entity Computer;


architecture Computer_arch of Computer is
signal instr_next, instr_calc 	: STD_LOGIC_VECTOR(31 downto 0);
signal instr_curr, instr_branch 	: STD_LOGIC_VECTOR(31 downto 0);
signal output, read_dataMem 	: STD_LOGIC_VECTOR(31 downto 0);
signal instr_addr : STD_LOGIC_VECTOR(7 downto 0);
signal PC_offset 	: STD_LOGIC_VECTOR(31 downto 0) := "00000000000000000000000000000100";
signal instr_extend_32 : STD_LOGIC_VECTOR(31 downto 0);
signal mem_out : STD_LOGIC_VECTOR(31 downto 0);
signal RegisterRd : STD_LOGIC_VECTOR(4 downto 0);
signal reg_data_feedback : STD_LOGIC_VECTOR(31 downto 0) := "00000000000000000000000000000000";
signal ALUresult : STD_LOGIC_VECTOR(31 downto 0);
signal ALU_op1, ALU_op2, ALU_op2_muxed : STD_LOGIC_VECTOR(31 downto 0);
signal Zero_reg : STD_LOGIC;
signal RegDst_C, ALUsrc_C : STD_LOGIC;
signal ALUop_C : STD_LOGIC_VECTOR(1 downto 0);
signal MemRead_C, Branch_C, MemWrite_C : STD_LOGIC;
signal data_C : STD_LOGIC;
signal MemtoReg_C, RegWrite_C : STD_LOGIC;
signal ALUsel : STD_LOGIC_VECTOR (3 downto 0);
signal Shiftmux_sel : STD_LOGIC;
signal branchInstr_out : STD_LOGIC_VECTOR(31 downto 0);

component mem IS
	PORT
	(
		address		: IN STD_LOGIC_VECTOR (7 DOWNTO 0);
		clock		: IN STD_LOGIC;
		data		: IN STD_LOGIC_VECTOR (31 DOWNTO 0);
		wren		: IN STD_LOGIC ;
		q		: OUT STD_LOGIC_VECTOR (31 DOWNTO 0)
	);
END component;

component regn
	Generic (N : INTEGER := 32);
	Port( D : IN STD_LOGIC_VECTOR(N-1 downto 0);
	      Clock, Resetn : IN STD_LOGIC;
			Q : OUT STD_LOGIC_VECTOR(N-1 downto 0));
end component;

component Adder
    Port ( address_in_p1 : in STD_LOGIC_VECTOR(31 downto 0);
	        address_in_p2 : in STD_LOGIC_VECTOR(31 downto 0);
           address_out : out STD_LOGIC_VECTOR(31 downto 0));
end component;
	
component sign_extend
	Port ( sign_16_in	: IN STD_LOGIC_VECTOR(15 downto 0);
			sign_32_out : OUT STD_LOGIC_VECTOR(31 downto 0));
end component;

component Instr_mux
	port(	A,B : in STD_LOGIC_VECTOR(4 downto 0);
			S: in STD_LOGIC;
			Z: out STD_LOGIC_VECTOR(4 downto 0));
end component;

component reg_unit
    Port (Clock : in STD_LOGIC;
			Reg_write_sig : in STD_LOGIC;
			reg_read_1, reg_read_2, write_reg_1 : in STD_LOGIC_VECTOR(4 downto 0);
			data_write : in STD_LOGIC_VECTOR(31 downto 0);
			read_out_1, read_out_2 : out STD_LOGIC_VECTOR(31 downto 0));
end component;

component ALU_mux
	port(	A,B : in STD_LOGIC_VECTOR(31 downto 0);
			S: in STD_LOGIC;
			Z: out STD_LOGIC_VECTOR(31 downto 0));
end component;

component ALU
	port(r_data_1, r_data_2  	 :  IN   STD_LOGIC_VECTOR(31 downto 0);   
		ALU_op      :  IN   STD_LOGIC_VECTOR(3 downto 0);
		Output      :  out  STD_LOGIC_VECTOR(31 downto 0);
		Zero 		: OUT STD_LOGIC);
end component; 

component Control_unit 
	port( opcode:					IN STD_LOGIC_VECTOR(5 downto 0);
			clk :  					IN STD_LOGIC;
			RegDst, Branch: 				OUT STD_LOGIC;
			RegWrite, ALUsrc: 				OUT STD_LOGIC;
			Mem_Read, Mem_Write: 				OUT STD_LOGIC;
			MemtoReg: 				OUT STD_LOGIC;
			ALUop:			OUT STD_LOGIC_VECTOR(1 downto 0));
end component;

component ALU_Control_unit
    Port ( 	ALUop             : in  std_logic_vector(1 downto 0);
				Function_instr       : in  std_logic_vector(5 downto 0);
				ALU_Sig: out std_logic_vector(3 downto 0));
end component;

component AND_gate
port(
  x0: in std_logic;
  x1: in std_logic;
  y: out std_logic);
end component;

component Shift_Left2
    Port(   instr  : in  std_logic_vector(31 downto 0);
				instr_out : out std_logic_vector(31 downto 0));
end component;
	
begin

DUT1: mem port map(instr_addr, clock, D, wren, mem_out);

Instr <= mem_out;

DUT2: regn port map (instr_next, clock, reg_reset, output);
DUT3: Adder port map (instr_curr, PC_offset, instr_calc);
DUT4: Control_Unit port map(mem_out(31 downto 26), clock, RegDst_C, Branch_C, RegWrite_C, ALUsrc_C, MemRead_C, MemWrite_C, MemtoReg_C, ALUop_C);
DUT5: ALU_Control_Unit port map(ALUop_C, mem_out(5 downto 0), ALUsel);

DUT6: Instr_mux port map(mem_out(20 downto 16), mem_out(15 downto 11), RegDst_C, RegisterRd);
DUT7: sign_extend port map(mem_out(15 downto 0),instr_extend_32); 
DUT8: reg_unit port map(clock, RegWrite_C, mem_out(25 downto 21), mem_out(20 downto 16), RegisterRd, reg_data_feedback, ALU_op1, ALU_op2);
DUT9: ALU_mux port map(ALU_op2, instr_extend_32, ALUsrc_C, ALU_op2_muxed);
DUT10: ALU port map(ALU_op1, ALU_op2_muxed, ALUsel, ALUresult, Zero_reg);

ALU_o <= ALUresult;

DUT11: AND_gate port map (Branch_C, Zero_Reg, Shiftmux_sel);
DUT12: Shift_Left2 port map (instr_extend_32, instr_branch);
DUT13: Adder port map (instr_calc, instr_branch, branchInstr_out);
DUT14: ALU_mux port map(instr_calc, branchInstr_out, Shiftmux_sel, instr_next);

process(MemRead_C, MemWrite_C)
	begin
	if (MemRead_C = '1') then
		data_C <= '0';
	elsif (MemWrite_C = '1') then
		data_C <= '1';
	else
		data_C <= '0';
	end if;
end process;

DUT15: mem port map(ALUresult(7 downto 0), clock, ALU_op2, data_C, read_dataMem);
DUT16: ALU_mux port map(ALUresult, read_dataMem, MemtoReg_C, reg_data_feedback);

Q <= reg_data_feedback;
dataMem <= read_dataMem;



process(reset, output, address)
	begin
	if reset = '1' then
		instr_curr <= "000000000000000000000000" & address;
	else
		instr_curr <= output;
	end if;
end process;

instr_addr <= instr_curr(7 downto 0);


end Computer_arch;