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
			RegWrite, ALUsrc, RegDst:     IN STD_LOGIC;
			ALU_operation :  IN STD_LOGIC_VECTOR(3 downto 0);
			Instr, Q: 				OUT STD_LOGIC_VECTOR(31 downto 0));
end entity Computer;


architecture Computer_arch of Computer is
signal instr_next 	: STD_LOGIC_VECTOR(31 downto 0);
signal instr_curr 	: STD_LOGIC_VECTOR(31 downto 0);
signal output 	: STD_LOGIC_VECTOR(31 downto 0);
signal instr_addr : STD_LOGIC_VECTOR(7 downto 0);
signal PC_offset 	: STD_LOGIC_VECTOR(31 downto 0) := "00000000000000000000000000000100";
signal instr_extend_32 : STD_LOGIC_VECTOR(31 downto 0);
signal mem_out : STD_LOGIC_VECTOR(31 downto 0);
signal RegisterRd : STD_LOGIC_VECTOR(4 downto 0);
signal reg_data_feedback : STD_LOGIC_VECTOR(31 downto 0) := "00000000000000000000000000000000";
signal ALU_op1, ALU_op2, ALU_op2_muxed : STD_LOGIC_VECTOR(31 downto 0);
signal Zero_reg : STD_LOGIC;


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
	
begin



DUT1: mem port map(instr_addr, clock, D, wren, mem_out);

Instr <= mem_out;

DUT2: regn port map (instr_next, clock, reg_reset, output);
DUT3: Adder port map (instr_curr, PC_offset, instr_next);
DUT4: Instr_mux port map(mem_out(20 downto 16), mem_out(15 downto 11), RegDst, RegisterRd);
DUT5: sign_extend port map(mem_out(15 downto 0),instr_extend_32); 
DUT6: reg_unit port map(clock, RegWrite, mem_out(25 downto 21), mem_out(20 downto 16), RegisterRd, reg_data_feedback, ALU_op1, ALU_op2);
DUT7: ALU_mux port map(ALU_op2, instr_extend_32, ALUsrc, ALU_op2_muxed);
DUT8: ALU port map(ALU_op1, ALU_op2_muxed, ALU_operation, reg_data_feedback, Zero_reg);

Q <= reg_data_feedback;

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