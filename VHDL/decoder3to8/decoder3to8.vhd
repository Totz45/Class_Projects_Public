-- ------------------------------------------------------
--   Place your design in this file
-- -------------------------------------------------------

-- DO NOT CHANGE THE FOLLOWING LIBRARY/USE PACKAGE LINES of CODE
library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity decoder3to8 is
	port ( sel : in STD_LOGIC_VECTOR (2 downto 0);
    		y  : out STD_LOGIC_VECTOR (7 downto 0));
end entity decoder3to8;

architecture behavior of decoder3to8 is
	begin
    	with sel select 
        y <= 	"10000000" when "111",
        		"01000000" when "110",
                "00100000" when "101",
                "00010000" when "100",
                "00001000" when "011",
                "00000100" when "010",
                "00000010" when "001",
                "00000001" when "000",
                "00000000" when others;
end behavior;