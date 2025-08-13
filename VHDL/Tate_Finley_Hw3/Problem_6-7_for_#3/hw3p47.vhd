----------------------------------
-- Tate Finley
-- ECE 3140
-- HW3 Problem 6
--
-- Implementation for problem 4.7

--Convert Gray code to BCD
----------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.all;

-- This design accepts a four-bit
-- unsigned binary number as input (in3
-- is MSb and in0 is LSb)
-- The design has four output Booleans:
--  out_47A: Msb of four bit output for BCD
--  out_47B: Next Msb of four bit output for BCD
--  out_47C: Third bit of four bit output for BCD
--  out_47D: Lsb of four bit output for BCD

entity hw3p47 is port(
  in3: in std_logic;
  in2: in std_logic;
  in1: in std_logic;
  in0: in std_logic;
  out_47A: out std_logic;
  out_47B: out std_logic;
  out_47C: out std_logic;
  out_47D: out std_logic);  
end entity hw3p47;

-- ---------------------------------------
--   THE Architecture OF YOUR DESIGN GOES IN THIS
--    SECTION. 
-- ---------------------------------------
architecture Logic47 of hw3p47 is
  
  component my_Output is
	port( x: in std_logic;
  	  	  y: out std_logic);
  end component;

  
  component my_Xor2 is
	port( x,y: in std_logic;
  	  		z: out std_logic);
  end component;

  component my_Xor3 is
	port( w,x,y: in std_logic;
  	  		z: out std_logic);
  end component;
  
  component my_Xor4 is
	port( w,x,y,z: in std_logic;
  	  		a: out std_logic);
  end component;
  
  begin
  -- Implementation of solution
    U0: my_Output port map (x=>in3, y=>out_47A);
    U1: my_Xor2 port map (x=>in3, y=>in2, z=>out_47B);
    U2: my_Xor3 port map (w=>in3, x=>in2, y=>in1, z=>out_47C);
    U3: my_Xor4 port map (w=>in3, x=>in2, y=>in1, z=>in0, a=>out_47D);
       
end architecture Logic47;