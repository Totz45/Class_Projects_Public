-------------------------------
--  Tate Finley
--  HW6 Problem 3
------------------------------

library IEEE;
use IEEE.STD_LOGIC_1164.all;

library work;
use work.TTU.all;

entity hw6p3 is 
 port (G_SENSOR_CS_N : OUT	STD_LOGIC;
		 G_SENSOR_SCLK : OUT	STD_LOGIC;
		 G_SENSOR_SDI  : INOUT	STD_LOGIC;
		 G_SENSOR_SDO  : INOUT	STD_LOGIC;	
		 CLOCK_50 : IN STD_LOGIC;
		 HEX2, HEX1, HEX0 : OUT STD_LOGIC_VECTOR(7 downto 0);
		 KEY0 : IN STD_LOGIC);
end hw6p3;

architecture design of hw6p3 is 
	component ADXL345_controller is port(
	
		reset_n     : IN STD_LOGIC;
		clk         : IN STD_LOGIC;
		data_valid  : OUT STD_LOGIC;
		data_x      : OUT STD_LOGIC_VECTOR(15 downto 0);
		data_y      : OUT STD_LOGIC_VECTOR(15 downto 0);
		data_z      : OUT STD_LOGIC_VECTOR(15 downto 0);
		SPI_SDI     : OUT STD_LOGIC;
		SPI_SDO     : IN STD_LOGIC;
		SPI_CSN     : OUT STD_LOGIC;
		SPI_CLK     : OUT STD_LOGIC
		
    );
	
    end component;
	 
	 component pll
		PORT
		(
			inclk0		: IN STD_LOGIC  := '0';
			c0		: OUT STD_LOGIC 
		);
	end component;
	
	constant sig_bits : integer := 12;
	signal c0_sig : std_logic;
	signal data_x, data_y, data_z : std_logic_vector(15 downto 0);
	signal tilt, reset_c : std_logic;
	signal counter: std_logic_vector(sig_bits-1 downto 0); 
	signal delay_c : integer := 100;
	
	begin
	--instantiate the clock and the accelerometer
	
	pll_inst : pll PORT MAP (inclk0	 => CLOCK_50,c0	 => c0_sig);
	
	U0: ADXL345_controller port map ('1', CLOCK_50, open, data_x, data_y, data_z, G_SENSOR_SDI, G_SENSOR_SDO, G_SENSOR_CS_N, G_SENSOR_SCLK);  
	
	--process for changing the steepness and direction of counting 
	change_direction: process(data_x)
	begin
		--first, determine direction
		if( data_x(11) = '1') then
			tilt <= '1';
			--determine steepness of right tilt
			case (data_x(7 downto 6)) is
					when "11" => delay_c <= 80;
					when "10" => delay_c <= 40;
					when "01" => delay_c <= 20;
					when "00" => delay_c <= 10;
					when others => delay_c <= 0;
			end case;

		else
			tilt <= '0';
			--determine steepness of left tilt
			case (data_x(7 downto 6)) is
					when "00" => delay_c <= 80;
					when "01" => delay_c <= 40;
					when "10" => delay_c <= 20;
					when "11" => delay_c <= 10;
					when others => delay_c <= 0;
			end case;
		end if;
	end process;
	
	--reset value feature using KEY0
	reset_state: process(KEY0)
	begin
		if(KEY0 = '0') then
			reset_c <= '1';
		else
			reset_c <= '0';
		end if;
	end process;
	
	
	--instantiate counter and output
	U1: entity work.my_UpDownCounter(arch_UpDown) generic map(NumBits=>sig_bits) port map (clock=>c0_sig,reset=>reset_c,direction=>tilt,Count_out=>counter,delay=>delay_c);
			
	U2: entity work.my_sevenSegment(RTL) port map (counter(3 downto 0), HEX0);
	U3: entity work.my_sevenSegment(RTL) port map (counter(7 downto 4), HEX1);
	U4: entity work.my_sevenSegment(RTL) port map (counter(11 downto 8), HEX2);
	

end design;