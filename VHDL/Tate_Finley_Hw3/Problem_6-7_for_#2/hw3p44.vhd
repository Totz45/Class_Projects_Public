----------------------------------
-- Tate Finley
-- ECE 3140
-- HW3 Problem 6
--
-- Implementation for problem 4.4
----------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.all;

-- This design accepts a three-bit
-- unsigned binary number as input (in2
-- is MSb and in0 is LSb)
-- The design has two output Booleans:
--  out_42A: output is 1 when the binary value
--  of the inputs is less than three
--  out_42B: output is 1 when the binary value
--  of the inputs is an even number

entity hw3p44 is port(
  in2: in std_logic;
  in1: in std_logic;
  in0: in std_logic;
  out_44A: out std_logic;
  out_44B: out std_logic);  
end entity hw3p44;

-- ---------------------------------------
--   THE Architecture OF YOUR DESIGN GOES IN THIS
--    SECTION. 
-- ---------------------------------------
architecture Logic44 of hw3p44 is
  signal in0bar, in1bar, in2bar : std_logic;
  signal temp1, temp2 : std_logic;
  
  component my_Inv is
	port( x: in std_logic;
  	  	  y: out std_logic);
  end component;
  
  component my_And2 is
	port( x,y: in std_logic;
  	  		z: out std_logic);
  end component;

  component my_Or2 is
	port( x,y: in std_logic;
  	  		z: out std_logic);
  end component;
  
  begin
  
    -----------------------------------
    -- Output for F
    -----------------------------------
    U0: my_Inv port map (in0, in0bar);
    U1: my_Inv port map (in1, in1bar);
    U2: my_Inv port map (in2, in2bar);
    U3: my_And2 port map (in2bar, in0bar, temp1);
    U4: my_And2 port map (in2bar, in1bar, temp2);
    U5: my_Or2 port map (temp1, temp2, out_44A);
    -----------------------------------
    -- Output for G
    -----------------------------------
    U10: my_Inv port map (in0, out_44B);
       
end architecture Logic44;
