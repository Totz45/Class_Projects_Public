-- File Name: Adder.vhd
-- Author: Tate Finley
-- Purpose: VHDL implementation of an adder.

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity Adder is
    Port ( address_in_p1 : in STD_LOGIC_VECTOR(31 downto 0);
	        address_in_p2 : in STD_LOGIC_VECTOR(31 downto 0);
           address_out : out STD_LOGIC_VECTOR(31 downto 0));
end Adder;

architecture Behavioral of Adder is
begin
    process(address_in_p1, address_in_p2)
    begin
        address_out <= address_in_p1 + address_in_p2; -- Add 4 to the input address
    end process;
end Behavioral;

