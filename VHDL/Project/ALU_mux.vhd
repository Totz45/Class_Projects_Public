-- File Name: ALU_mux.vhd
-- Author: Tate Finley
-- Purpose: Implementation of a multiplexer for the ALU.

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity ALU_mux is
	port(	A,B : in STD_LOGIC_VECTOR(31 downto 0);
			S: in STD_LOGIC;
			Z: out STD_LOGIC_VECTOR(31 downto 0));
end ALU_mux;
 
architecture behavioral of ALU_MUX is
	begin
	process (S,A,B) is
		begin
			if (S ='0') then
				Z <= A;
			else
				Z <= B;
			end if;
	end process;
end behavioral;