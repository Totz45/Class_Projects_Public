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
			Instr, Reg_out1, Reg_out2: 				OUT STD_LOGIC_VECTOR(31 downto 0);
			ALU_o, data_mem, Q: 				OUT STD_LOGIC_VECTOR(31 downto 0));
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
signal MEM_bits_C, MEM_IDEX, MEM_EXMEM: STD_LOGIC_VECTOR(2 downto 0) := "000";
signal WB_bits_C, WB_IDEX, WB_EXMEM, WB_MEMWB: STD_LOGIC_VECTOR(1 downto 0) := "00";
signal EX_bits_C, EX_IDEX: STD_LOGIC_VECTOR(3 downto 0) := "0000";
signal data_C : STD_LOGIC;
signal ALUsel : STD_LOGIC_VECTOR (3 downto 0);
signal Shiftmux_sel : STD_LOGIC;
signal branchInstr_out : STD_LOGIC_VECTOR(31 downto 0);
signal reset_i : STD_LOGIC := '0';
signal instrMem_IDEX, pc4_IDEX	: STD_LOGIC_VECTOR(31 downto 0);
signal signExtend_EXMEM, pc4_EXMEM	: STD_LOGIC_VECTOR(31 downto 0);
signal ALU_op1_EXMEM, ALU_op2_EXMEM	: STD_LOGIC_VECTOR(31 downto 0);
signal rt, rs, rd_MEMWB, rd_WB : STD_LOGIC_VECTOR(4 downto 0);
signal zero_reg_MEMWB : STD_LOGIC;
signal pc_MEMWB, ALUresult_MEMWB	: STD_LOGIC_VECTOR(31 downto 0);
signal ALU_op_MEMWB	: STD_LOGIC_VECTOR(31 downto 0);
signal dataMem_WB, ALUresult_WB : STD_LOGIC_VECTOR(31 downto 0);

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
			EX: 				OUT STD_LOGIC_VECTOR(3 downto 0);
			MEM: 				OUT STD_LOGIC_VECTOR(2 downto 0);
			WB:			OUT STD_LOGIC_VECTOR(1 downto 0));
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

component IFID_reg
	port( clk       : in  std_logic;
			rst       : in  std_logic; 
			pc4_in:					IN STD_LOGIC_VECTOR(31 downto 0);
			instrMem_in:  					IN STD_LOGIC_VECTOR(31 downto 0);
			pc4_out: 				OUT STD_LOGIC_VECTOR(31 downto 0);
			instrMem_out: 				OUT STD_LOGIC_VECTOR(31 downto 0));
end component;
	
component IDEX_reg
    Port (clk           : in  std_logic;
        rst           : in  std_logic;
        WB_in         : in  std_logic_vector(1 downto 0);
        MEM_in        : in  std_logic_vector(2 downto 0);
        EX_in         : in  std_logic_vector(3 downto 0);
		  pc4_in         : in  std_logic_vector(31 downto 0);
        read_data1_in : in  std_logic_vector(31 downto 0);
        read_data2_in : in  std_logic_vector(31 downto 0);
        sign_ext_in   : in  std_logic_vector(31 downto 0);
        rs_in         : in  std_logic_vector(4 downto 0);
        rt_in         : in  std_logic_vector(4 downto 0);
        WB_out        : out std_logic_vector(1 downto 0);
        MEM_out       : out std_logic_vector(2 downto 0);
        EX_out        : out std_logic_vector(3 downto 0);
		  pc4_out        : out std_logic_vector(31 downto 0);
        read_data1_out: out std_logic_vector(31 downto 0);
        read_data2_out: out std_logic_vector(31 downto 0);
        sign_ext_out  : out std_logic_vector(31 downto 0);
        rs_out        : out std_logic_vector(4 downto 0);
        rt_out        : out std_logic_vector(4 downto 0));
end component;

component EXMEM_reg
    Port (clk           : in  std_logic;
        rst           : in  std_logic; 
        WB_in         : in  std_logic_vector(1 downto 0);  
        MEM_in        : in  std_logic_vector(2 downto 0);  
		  pc_in         : in  std_logic_vector(31 downto 0);
        Zero_reg_in   : in  std_logic;
		  ALU_result_in : in  std_logic_vector(31 downto 0);
        read_data2_in : in  std_logic_vector(31 downto 0);
        rd_in         : in  std_logic_vector(4 downto 0);
        WB_out        : out std_logic_vector(1 downto 0);
        MEM_out       : out std_logic_vector(2 downto 0);
		  pc_out        : out std_logic_vector(31 downto 0);
		  Zero_reg_out  : out std_logic;
        ALU_result_out : out std_logic_vector(31 downto 0);
        read_data2_out: out std_logic_vector(31 downto 0);
        rd_out        : out std_logic_vector(4 downto 0));
end component;

component MEMWB_reg
    Port (clk           : in  std_logic;
        rst           : in  std_logic; 
        WB_in         : in  std_logic_vector(1 downto 0);
		  data_mem_in : in  std_logic_vector(31 downto 0);
		  ALU_result_in : in  std_logic_vector(31 downto 0);
        rd_in         : in  std_logic_vector(4 downto 0);
        WB_out        : out std_logic_vector(1 downto 0);
        data_mem_out: out std_logic_vector(31 downto 0);
		  ALU_result_out : out std_logic_vector(31 downto 0);
        rd_out        : out std_logic_vector(4 downto 0));
end component;
	
begin

DUT1: ALU_mux port map(instr_calc, pc_MEMWB, Shiftmux_sel, instr_next);
DUT2: regn port map (instr_next, clock, reg_reset, output);
DUT3: Adder port map (instr_curr, PC_offset, instr_calc);
DUT4: mem port map(instr_addr, clock, D, wren, mem_out);

process(reset, output, address)
	begin
	if reset = '1' then
		instr_curr <= "000000000000000000000000" & address;
	else
		instr_curr <= output;
	end if;
end process;

instr_addr <= instr_curr(7 downto 0);

Instr <= mem_out;

DUT5: IFID_reg port map (clock, reset_i, instr_calc, mem_out, pc4_IDEX, instrMem_IDEX);

DUT6: Control_Unit port map(instrMem_IDEX(31 downto 26), clock, EX_bits_C, MEM_bits_C, WB_bits_C);
DUT7: reg_unit port map(clock, WB_MEMWB(1), instrMem_IDEX(25 downto 21), instrMem_IDEX(20 downto 16), rd_WB, reg_data_feedback, ALU_op1, ALU_op2);
DUT8: sign_extend port map(instrMem_IDEX(15 downto 0), instr_extend_32); 

Reg_out1 <= ALU_op1;
Reg_out2 <= ALU_op2;

DUT9: IDEX_reg port map (clock, reset_i, WB_bits_C, MEM_bits_C, EX_bits_C, pc4_IDEX, ALU_op1, ALU_op2, instr_extend_32, instrMem_IDEX(20 downto 16), instrMem_IDEX(15 downto 11), WB_IDEX, MEM_IDEX, EX_IDEX, pc4_EXMEM, ALU_op1_EXMEM, ALU_op2_EXMEM, signExtend_EXMEM, rs, rt);


DUT10: ALU_Control_Unit port map(EX_IDEX(2 downto 1), signExtend_EXMEM(5 downto 0), ALUsel);
DUT11: Shift_Left2 port map (signExtend_EXMEM, instr_branch);
DUT12: Adder port map (pc4_EXMEM, instr_branch, branchInstr_out);
DUT13: Instr_mux port map(rs, rt, EX_IDEX(3), RegisterRd);
DUT14: ALU_mux port map(ALU_op2_EXMEM, signExtend_EXMEM, EX_IDEX(0), ALU_op2_muxed);
DUT15: ALU port map(ALU_op1_EXMEM, ALU_op2_muxed, ALUsel, ALUresult, Zero_reg);

ALU_o <= ALUresult;

DUT16: EXMEM_reg port map (clock, reset_i, WB_IDEX, MEM_IDEX, branchInstr_out, Zero_reg, ALUresult, ALU_op2_EXMEM, RegisterRd, WB_EXMEM, MEM_EXMEM, pc_MEMWB, zero_reg_MEMWB, ALUresult_MEMWB, ALU_op_MEMWB, rd_MEMWB);

DUT17: AND_gate port map (MEM_EXMEM(2), zero_reg_MEMWB, Shiftmux_sel);

process(MEM_EXMEM(1 downto 0))
	begin
	if (MEM_EXMEM(1) = '1') then
		data_C <= '0';
	elsif (MEM_EXMEM(0)= '1') then
		data_C <= '1';
	else
		data_C <= '0';
	end if;
end process;

DUT18: mem port map(ALUresult_MEMWB(7 downto 0), clock, ALU_op_MEMWB, data_C, read_dataMem);

data_mem <= read_dataMem;

DUT19: MEMWB_reg port map (clock, reset_i, WB_EXMEM, read_dataMem, ALUresult_MEMWB, rd_MEMWB, WB_MEMWB, dataMem_WB, ALUresult_WB, rd_WB);

DUT20: ALU_mux port map(ALUresult_WB, dataMem_WB, WB_MEMWB(0), reg_data_feedback);

Q <= reg_data_feedback;


end Computer_arch;