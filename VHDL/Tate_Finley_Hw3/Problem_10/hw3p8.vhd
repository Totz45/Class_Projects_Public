-- Tate Finley
-- ECE 3140
-- Hw3 Problem 10


-- ------------------------------------------------------
--   Place your design in this file
-- -------------------------------------------------------

-- DO NOT CHANGE THE FOLLOWING LIBRARY/USE PACKAGE LINES of CODE

-- --------------------------------------
--    DEFINE YOUR DESIGNS INTERFACE
--    INPUTS AND OUTPUTS MUST BE DEFINED
-- --------------------------------------

-- --------------------------------------
--    Inverter with 1 ns delay
-- --------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity inv_d1 is port(
	A: in std_logic;
    Y: out std_logic);
end entity inv_d1;

architecture logicInv of inv_d1 is
begin
   Y <= not A after 1ns;
end architecture logicInv;

-- --------------------------------------
--    2 input And with 3 ns delay
-- --------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity and2_d3 is port(
	A,B: in std_logic;
    Y: out std_logic);
end entity and2_d3;

architecture logicAnd2 of and2_d3 is
begin
   Y <= A and B after 3ns;
end architecture logicAnd2;

-- --------------------------------------
--    2 input Or with 3 ns delay
-- --------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.all;

entity or2_d3 is port(
	A,B: in std_logic;
    Y: out std_logic);
end entity or2_d3;

architecture logicOr2 of or2_d3 is
begin
   Y <= A or B after 3ns;
end architecture logicOr2;

-- --------------------------------------
--    hw3 problem 8 with struct 2 architecture
-- --------------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.all;


entity hw3p8 is port(
  in_a: in STD_LOGIC;
  in_b: in STD_LOGIC;
  in_c: in STD_LOGIC;
  out_f: out STD_LOGIC); 
end entity hw3p8;

architecture struct2 of hw3p8 is
  signal in_abar, in_bbar, in_cbar : STD_LOGIC;
  signal temp4 : STD_LOGIC;
  signal temp5 : STD_LOGIC;
  
  component inv_d1
   port(A: in STD_LOGIC;
        Y: out STD_LOGIC);
  end component;
  component and2_d3
   port(A,B: in STD_LOGIC;
        Y: out STD_LOGIC);
  end component;
  component or2_d3
   port(A,B: in STD_LOGIC;
        Y: out STD_LOGIC);
  end component;
  
  begin
    U0: inv_d1 port map (in_a, in_abar);
    U1: inv_d1 port map (in_b, in_bbar);
    U2: inv_d1 port map (in_c, in_cbar);
    
    -- Minimal SOP implementation of F((a,b,c) = SUM m(1,5,6,7)
    -- using SOP, the output out_f = in_b# in_c + in_a in_b
    U10: and2_d3 port map (in_bbar, in_c, temp4);
    U11: and2_d3 port map (in_a, in_b, temp5);
    U12: or2_d3 port map (temp5, temp4, out_f);

    
end architecture struct2;