-- File Name: sign_extend.vhd
-- Author: Tate Finley
-- Purpose: sign extends the 16th bit to make the address 32 bits.

Library ieee;
use       ieee.std_logic_1164.all;

entity sign_extend is
	port( sign_16_in	: IN STD_LOGIC_VECTOR(15 downto 0);
			sign_32_out : OUT STD_LOGIC_VECTOR(31 downto 0));
end entity sign_extend; 

architecture behavioral of sign_extend is
begin	
	process(sign_16_in)
	begin
		sign_32_out(15 downto 0) <= sign_16_in;
		for i in 16 to 31 loop
			sign_32_out(i) <= sign_16_in(15);
		end loop;
	end process;
end behavioral;