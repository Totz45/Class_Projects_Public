library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Control_unit is 
	port( opcode:					IN STD_LOGIC_VECTOR(5 downto 0);
			clk :  					IN STD_LOGIC;
			RegDst, Branch: 				OUT STD_LOGIC;
			RegWrite, ALUsrc: 				OUT STD_LOGIC;
			Mem_Read, Mem_Write: 				OUT STD_LOGIC;
			MemtoReg: 				OUT STD_LOGIC;
			ALUop:			OUT STD_LOGIC_VECTOR(1 downto 0));
end entity Control_unit;

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

architecture Behavioral of Control_unit is
signal RegDst_sig : STD_LOGIC;
signal Branch_sig : STD_LOGIC;
signal RegWrite_sig : STD_LOGIC;
signal ALUsrc_sig   : STD_LOGIC;
signal Mem_Read_sig  : STD_LOGIC;
signal Mem_Write_sig : STD_LOGIC;
signal MemtoReg_sig : STD_LOGIC;
signal ALUop_sig : STD_LOGIC_VECTOR(1 downto 0);

begin
    process(opcode)
    begin
			  -- Default signal settings
			  RegDst_sig   <= '0';
			  Branch_sig   <= '0';
			  RegWrite_sig <= '0';
			  ALUsrc_sig   <= '0';
			  Mem_Read_sig  <= '0';
			  Mem_Write_sig <= '0';
			  MemtoReg_sig <= '0';
			  ALUop_sig    <= "00";
			  
			  case opcode is
					when "000000" => -- R-type instructions
						 RegDst_sig   <= '1';
						 RegWrite_sig <= '1';
						 ALUsrc_sig   <= '0';
						 MemtoReg_sig <= '0';
						 Mem_Read_sig  <= '0';
						 Mem_Write_sig <= '0';
						 Branch_sig   <= '0';
						 ALUop_sig    <= "10";  -- R-type
						 
					when "100011" => -- lw
						 RegDst_sig   <= '0';
						 RegWrite_sig <= '1';
						 ALUsrc_sig   <= '1';
						 MemtoReg_sig <= '1';
						 Mem_Read_sig  <= '1';
						 Mem_Write_sig <= '0';
						 Branch_sig   <= '0';
						 ALUop_sig    <= "00";  -- I-type
						 
					when "101011" => -- sw
						 RegWrite_sig <= '0';
						 ALUsrc_sig   <= '1';
						 Mem_Read_sig  <= '0';
						 Mem_Write_sig <= '1';
						 Branch_sig   <= '0';
						 ALUop_sig    <= "00";  -- I-type
						 
					when "000100" => -- beq
						 RegWrite_sig <= '0';
						 ALUsrc_sig   <= '0';
						 Mem_Read_sig  <= '0';
						 Mem_Write_sig <= '0';
						 Branch_sig   <= '1';  -- Branch condition signal
						 ALUop_sig    <= "01";  -- Branch I-type
						 
					when "001000" => -- addi
						 RegDst_sig   <= '0';  -- destination register is rt
						 RegWrite_sig <= '1';
						 ALUsrc_sig   <= '1';
						 MemtoReg_sig <= '0';
						 Mem_Read_sig  <= '0';
						 Mem_Write_sig <= '0';
						 Branch_sig   <= '0';
						 ALUop_sig    <= "00";  -- I-type
						 
					when others =>
						 null;
			  end case; 
		 end process;
		 
		 RegDst <= RegDst_sig;
		 Branch <= Branch_sig;
		 RegWrite <= RegWrite_sig;
		 ALUsrc <= ALUsrc_sig;
		 Mem_Read <= Mem_Read_sig;
		 Mem_Write <= Mem_Write_sig;
		 MemtoReg <= MemtoReg_sig;
		 ALUop <= ALUop_sig;
		
end Behavioral;