-- Tate Finley
-- ECE 3140
-- Hw3 Problem 8
-- Use with TTU.vhdl


-- ------------------------------------------------------
--   Place your design in this file
-- -------------------------------------------------------

-- DO NOT CHANGE THE FOLLOWING LIBRARY/USE PACKAGE LINES of CODE
library IEEE;
use IEEE.STD_LOGIC_1164.all;

library work;
use work.TTU.all;


-- --------------------------------------
--    DEFINE YOUR DESIGNS INTERFACE
--    INPUTS AND OUTPUTS MUST BE DEFINED
-- --------------------------------------

-- This example design accepts a four-bit
-- unsigned binary number as input (in3
-- is MSb and in0 is LSb)
-- The design has three output Booleans:
--  out_c: Does the input number match one
--         of the course numbers (2, 1, or 0)?
--         TRUE or FALSE
--  out_p: Is the input number prime?
--  out_f: Is the input number one of the
--         Fibonacci sequence?
entity hw3p8 is port(
  in_a: in STD_LOGIC;
  in_b: in STD_LOGIC;
  in_c: in STD_LOGIC;
  out_f: out STD_LOGIC); 
end entity hw3p8;

-- ---------------------------------------
--   THE CRUX OF YOUR DESIGN GOES IN THIS
--    SECTION.  SPECIFICALLY, 
-- ---------------------------------------
architecture struct1 of hw3p8 is
  signal in_abar, in_bbar, in_cbar : STD_LOGIC;
  signal temp4 : STD_LOGIC;
  signal temp5 : STD_LOGIC;

  begin
    U0: entity work.INV(RTL) port map (in_a, in_abar);
    U1: entity work.INV(RTL) port map (in_b, in_bbar);
    U2: entity work.INV(RTL) port map (in_c, in_cbar);
    
    -- Minimal SOP implementation of F((a,b,c) = SUM m(1,5,6,7)
    -- using SOP, the output out_f = in_b# in_c + in_a in_b
    U10: entity work.AND2(RTL) port map (in_bbar, in_c, temp4);
    U11: entity work.AND2(RTL) port map (in_a, in_b, temp5);
    U12: entity work.OR2(RTL) port map (temp5, temp4, out_f);

    
end architecture struct1;