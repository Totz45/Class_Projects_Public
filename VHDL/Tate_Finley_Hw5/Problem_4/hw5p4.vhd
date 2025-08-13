library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

library work;
use work.TTU.all;

entity hw5p4 is 
	port( SW0: in std_logic;
			KEY : in std_logic_vector(1 downto 0);
			CLOCK_50 : in std_logic;
			HEX4 : out std_logic_vector(7 downto 0);
			HEX5 : out std_logic_vector(7 downto 0);
			ARDUINO_IO12 : out std_logic);
end hw5p4;

architecture RTL of hw5p4 is 
	component pll is PORT
		(inclk0		: IN STD_LOGIC  := '0';
			c0		: OUT STD_LOGIC);
	end component;
	
	component hw5p3 is 
	port( Clock, SetState: in std_logic;
			o_LFSR : out std_logic_vector(4 downto 0));
   end component;
	
	component my_sevenSegment is port(
		sel : in STD_LOGIC_VECTOR (3 downto 0);
		sevSeg: out std_logic_vector(7 downto 0));
	end component;
	
	signal Mhz1 : std_logic;
	signal CLK : std_logic := '0';
	signal Set : std_logic;
	signal RandomNumber : std_logic_vector(4 downto 0);
	signal MsbSeven, LsbSeven : std_logic_vector(3 downto 0);
	
	begin
	
	pll_inst : pll PORT MAP (inclk0=> CLOCK_50,c0=> Mhz1);
	
	process (SW0, KEY(0), Mhz1)
	begin 
		if(SW0 = '1' and KEY(0) = '0') then
			--if(KEY(0) = '0') then
				CLK <= '1';
			--else
		elsif(SW0 = '1' and KEY(0) = '1') then
				CLK <= '0';
		elsif(SW0 = '0' and KEY(0) = '0' and Mhz1 ='1') then	
				CLK <= not CLK;
			--end if;
		   --if(rising_edge(Mhz1)) then
				--CLK <= not CLK;
			--end if;
		end if;
	end process;
	
	process (KEY(1))
	begin
		if(KEY(1) = '0') then
		   Set <= '1';
		else
			Set <= '0';
		end if;
	end process;
		
	
	U0: hw5p3 port map (Clock=>CLK,SetState=>Set,o_LFSR=>RandomNumber);

	MsbSeven(3) <= '0';
	MsbSeven(2) <= '0';
	MsbSeven(1) <= '0';
	MsbSeven(0) <= RandomNumber(4);
	
	Assign: process (RandomNumber)
	begin
		for i in 0 to 3 loop
			LsbSeven(i) <= RandomNumber(i);
		end loop;
	end process;
	
	U1: entity work.my_sevenSegment port map(sel=>MsbSeven,sevSeg=>HEX5);
	U2: entity work.my_sevenSegment port map(sel=>LsbSeven,sevSeg=>HEX4);
	
	process(CLK)
	begin
		if (CLK = '1') then
			ARDUINO_IO12 <= '1';
		else
			ARDUINO_IO12 <= '0';
		end if;
	end process;
	
	
end RTL;
