-- File Name: reg_unit_registers.vhd
-- Author: Tate Finley
-- Purpose: Definition for a single register.

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity reg_unit_registers is
    Port ( Clock : in STD_LOGIC;
           C : in STD_LOGIC;
           D : in STD_LOGIC_VECTOR(31 downto 0);
           Q : out STD_LOGIC_VECTOR(31 downto 0));
end reg_unit_registers;

architecture Behavioral of reg_unit_registers is
signal start_program : std_logic := '0';
begin
    process (Clock)
    begin
        if (start_program = '0') then
				Q <= "00000000000000000000000000000000";
		      start_program <= '1';
		  elsif rising_edge(Clock) then
            if C = '1' then
                Q <= D;
            end if;
        end if;
    end process;
end Behavioral;
