-- File Name: ALU.vhd
-- Author: Tate Finley
-- Purpose: Implementation of add, subtract, and, or, xor, and nor operands.

library   ieee;
use       ieee.std_logic_1164.all;
use       ieee.std_logic_signed.all; --addition and subtraction operands

entity ALU is 
	port(r_data_1, r_data_2  	 :  IN   STD_LOGIC_VECTOR(31 downto 0);   
		ALU_op      :  IN   STD_LOGIC_VECTOR(3 downto 0);
		Output      :  out  STD_LOGIC_VECTOR(31 downto 0);
		Zero 		: OUT STD_LOGIC);
end ALU; 

ARCHITECTURE behavior OF ALU IS

signal temp : STD_LOGIC_VECTOR (31 downto 0);

BEGIN
	
	Process(r_data_1, r_data_2, ALU_op)
	Begin
		IF(ALU_op = "0000") THEN
			temp <= r_data_1 AND r_data_2;
		ELSIF(ALU_op = "0001") THEN
			temp <= r_data_1 OR r_data_2;
		ELSIF(ALU_op = "0010") THEN
			temp <= r_data_1 + r_data_2;
		ELSIF(ALU_op = "0110") THEN
			temp <= r_data_1 - r_data_2;
		ELSIF(ALU_op = "0111") THEN
			temp <= r_data_1 XOR r_data_2;
		ELSIF(ALU_op = "1100") THEN
			temp <= r_data_1 NOR r_data_2;
		end if;
		
	end process;
	
	Process(temp)
	begin
		IF(temp = "00000000000000000000000000000000") THEN
			Zero <= '1';
		ELSE
			Zero <= '0';
		END IF;
	end process;
	
	Output <= temp;
	
end behavior;