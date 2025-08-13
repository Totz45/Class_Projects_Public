---------------------------------
-- Tate Finley
-- ECE 3140
-- PE2: move paddle with rotary encoder 
--	(pong implementation)
---------------------------------


---------------------------------
--	References and IP used
--
-- components from vga_top including
-- 	vga_controller
--		vga_pll_25_175
-- 	hw_image_generator (adjusted for PE2)
-- individual IP from
--		hw7p1 (implementing screen format)
-- 	hw7p3 (making screen elements move)
-- components101.com regarding
-- 	rotary encoder behavior
-- The KY-040 datasheet which contains
-- 	sample implementation using Arduino code not vhdl
-- contact from Lewis Bates, and Michael West
-- 	though little information about PE2 was discussed prior to submission
-- 	there was no copying or direct sharing of IP
--		Lewis was doing pong
--		Micheal was doing breakout
--	Chat GTP was used to generate ideas such as
-- 	using a biderectional input for the ARDUINO_IO's
--		no direct vhdl generated from AI was used in this project
---------------------------------

library   ieee;
use       ieee.std_logic_1164.all;

entity PE2 is
	
	port(
	
		-- Inputs for image generation
		
		pixel_clk_m		:	IN	STD_LOGIC;     -- pixel clock for VGA mode being used 
		reset_n_m		:	IN	STD_LOGIC; --active low asycnchronous reset
		
		-- Outputs for image generation 
		
		h_sync_m		:	OUT	STD_LOGIC;	--horiztonal sync pulse
		v_sync_m		:	OUT	STD_LOGIC;	--vertical sync pulse 
		
		ARDUINO_IO6 : 	INOUT		STD_LOGIC; 
		ARDUINO_IO7 : 	INOUT 	STD_LOGIC;
		
		red_m      :  OUT  STD_LOGIC_VECTOR(3 DOWNTO 0) := (OTHERS => '0');  --red magnitude output to DAC
		green_m    :  OUT  STD_LOGIC_VECTOR(3 DOWNTO 0) := (OTHERS => '0');  --green magnitude output to DAC
		blue_m     :  OUT  STD_LOGIC_VECTOR(3 DOWNTO 0) := (OTHERS => '0') --blue magnitude output to DAC
		
	
	);
	
end PE2;

architecture vga of PE2 is

	component vga_pll_25_175 is 
	
		port(
		
			inclk0		:	IN  STD_LOGIC := '0';  -- Input clock that gets divided (50 MHz for max10)
			c0			:	OUT STD_LOGIC          -- Output clock for vga timing (25.175 MHz)
		
		);
		
	end component;
	
	component vga_controller is 
	
		port(
		
			pixel_clk	:	IN	STD_LOGIC;	--pixel clock at frequency of VGA mode being used
			reset_n		:	IN	STD_LOGIC;	--active low asycnchronous reset
			h_sync		:	OUT	STD_LOGIC;	--horiztonal sync pulse
			v_sync		:	OUT	STD_LOGIC;	--vertical sync pulse
			disp_ena	:	OUT	STD_LOGIC;	--display enable ('1' = display time, '0' = blanking time)
			column		:	OUT	INTEGER;	--horizontal pixel coordinate
			row			:	OUT	INTEGER;	--vertical pixel coordinate
			n_blank		:	OUT	STD_LOGIC;	--direct blacking output to DAC
			n_sync		:	OUT	STD_LOGIC   --sync-on-green output to DAC
		
		);
		
	end component;
	
	component hw_image_generator is
	
		port(
			Clocking : IN STD_LOGIC;
			CLK :  INOUT  STD_LOGIC;
			DT : INOUT   STD_LOGIC;
			disp_ena :  IN  STD_LOGIC;  --display enable ('1' = display time, '0' = blanking time)
			row      :  IN  INTEGER;    --row pixel coordinate
			column   :  IN  INTEGER;    --column pixel coordinate
			red      :  OUT STD_LOGIC_VECTOR(3 DOWNTO 0) := (OTHERS => '0');  --red magnitude output to DAC
			green    :  OUT STD_LOGIC_VECTOR(3 DOWNTO 0) := (OTHERS => '0');  --green magnitude output to DAC
			blue     :  OUT STD_LOGIC_VECTOR(3 DOWNTO 0) := (OTHERS => '0')   --blue magnitude output to DAC
		
		);
		
	end component;
	
	
	signal pll_OUT_to_vga_controller_IN, dispEn : STD_LOGIC;
	signal rowSignal, colSignal : INTEGER;
	
	
begin

-- Just need 3 components for VGA system 
	U1	:	vga_pll_25_175 port map(pixel_clk_m, pll_OUT_to_vga_controller_IN);
	U2	:	vga_controller port map(pll_OUT_to_vga_controller_IN, reset_n_m, h_sync_m, v_sync_m, dispEn, colSignal, rowSignal, open, open);
	U3	:	hw_image_generator port map(pixel_clk_m, ARDUINO_IO6, ARDUINO_IO7, dispEn, rowSignal, colSignal, red_m, green_m, blue_m);
	

end vga;