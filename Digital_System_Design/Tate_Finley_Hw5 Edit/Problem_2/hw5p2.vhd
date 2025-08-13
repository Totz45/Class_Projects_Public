library IEEE;
use IEEE.STD_LOGIC_1164.all;

library work;
use work.TTU.all;

entity hw5p2 is port(
  SW0: in STD_LOGIC;
  SW9: in STD_LOGIC;
  SW1: in STD_LOGIC;
  HEX5: out STD_LOGIC_VECTOR(7 downto 0);
  LEDR0: out STD_LOGIC);  
end entity hw5p2;

-- ---------------------------------------
--   THE CRUX OF YOUR DESIGN GOES IN THIS
--    SECTION.  SPECIFICALLY, 
-- ---------------------------------------
architecture ST of hw5p2 is

	component hw5p1 is port(
			x: in STD_LOGIC;
			CLK: in STD_LOGIC;
			Reset: in STD_LOGIC;
			sevSeg: out STD_LOGIC_VECTOR(7 downto 0);
			z: out STD_LOGIC);  
	end component;
	
	begin
		U0: hw5p1 port map(x=>SW0,CLK=>SW9,Reset=>SW1,sevSeg=>HEX5,z=>LEDR0);
	
	
    --U0: entity work.my_INV(RTL) port map (in0, in0bar);

    
end architecture ST;