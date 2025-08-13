-- File Name: Register_decoder.vhd
-- Author: Tate Finley
-- Purpose: decoder for inside the register unit.

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity Register_decoder is
	port(	S: in STD_LOGIC_VECTOR(4 downto 0);
			Z: out STD_LOGIC_VECTOR(31 downto 0));
end Register_decoder;
 
architecture behavioral of Register_decoder is
	begin
	process (S) is
		begin
			-- Register number to one-hot encoding of registers
			Z <= (others => '0');
			Z(to_integer(unsigned(S))) <= '1';
	end process;
end behavioral;