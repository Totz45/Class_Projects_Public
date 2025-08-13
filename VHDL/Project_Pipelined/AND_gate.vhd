-- File Name: Register_mux.vhd
-- Author: Tate Finley
-- Purpose: VHDL implementation of and gate.

Library ieee;
use ieee.std_logic_1164.all;

entity AND_gate is
port(
  x0: in std_logic;
  x1: in std_logic;
  y: out std_logic);
end AND_gate;

architecture RTL of AND_gate is
begin
  process(x1, x0) is
  begin
    y <= x1 and x0;
  end process;
end RTL;