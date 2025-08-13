library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Shift_Left2 is
    Port(   instr  : in  std_logic_vector(31 downto 0);
				instr_out : out std_logic_vector(31 downto 0));
end Shift_Left2;

architecture Behavioral of Shift_Left2 is
begin
    -- Concatenate bits 29 downto 0 with two zeros on the right.
    instr_out <= instr(29 downto 0) & "00";
end Behavioral;
