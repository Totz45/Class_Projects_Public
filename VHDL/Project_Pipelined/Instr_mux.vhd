-- File Name: Instr_mux.vhd
-- Author: Tate Finley
-- Purpose: multiplexer for the write register input accounting for different instruction types.

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Instr_mux is
	port(	A,B : in STD_LOGIC_VECTOR(4 downto 0);
			S: in STD_LOGIC;
			Z: out STD_LOGIC_VECTOR(4 downto 0));
end Instr_mux;
 
architecture behavioral of Instr_MUX is
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