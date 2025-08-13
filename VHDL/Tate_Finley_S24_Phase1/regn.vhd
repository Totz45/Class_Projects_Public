-- File Name: regn.vhd
-- Author: Tate Finley
-- Purpose: Registers for holding input.

Library ieee;
use ieee.std_logic_1164.all;

entity regn is
	Generic (N : INTEGER);
	Port( D : IN STD_LOGIC_VECTOR(N-1 downto 0);
	      Clock, Resetn : IN STD_LOGIC;
			Q : OUT STD_LOGIC_VECTOR(N-1 downto 0));
end entity regn;

architecture behavioral of regn is
signal reg_q : STD_LOGIC_VECTOR (31 DOWNTO 0);
begin
	process(Clock, Resetn)
	begin
		if Resetn = '1' then
          reg_q <= (others => '0');
      elsif rising_edge(Clock) then
          reg_q <= D;
      end if;
   end process;
	
	Q <= reg_q;
end behavioral;