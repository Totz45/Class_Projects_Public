--------------------------------------------------------------------------------
--
--   FileName:         hw_image_generator.vhd
--   Dependencies:     none
--   Design Software:  Quartus II 64-bit Version 12.1 Build 177 SJ Full Version
--
--   HDL CODE IS PROVIDED "AS IS."  DIGI-KEY EXPRESSLY DISCLAIMS ANY
--   WARRANTY OF ANY KIND, WHETHER EXPRESS OR IMPLIED, INCLUDING BUT NOT
--   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
--   PARTICULAR PURPOSE, OR NON-INFRINGEMENT. IN NO EVENT SHALL DIGI-KEY
--   BE LIABLE FOR ANY INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL
--   DAMAGES, LOST PROFITS OR LOST DATA, HARM TO YOUR EQUIPMENT, COST OF
--   PROCUREMENT OF SUBSTITUTE GOODS, TECHNOLOGY OR SERVICES, ANY CLAIMS
--   BY THIRD PARTIES (INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF),
--   ANY CLAIMS FOR INDEMNITY OR CONTRIBUTION, OR OTHER SIMILAR COSTS.
--
--   Version History
--   Version 1.0 05/10/2013 Scott Larson
--     Initial Public Release
--    
--------------------------------------------------------------------------------
--
-- Altered 10/13/19 - Tyler McCormick 
-- Test pattern is now 8 equally spaced 
-- different color vertical bars, from black (left) to white (right)


LIBRARY ieee;
USE ieee.std_logic_1164.all;
USE ieee.std_logic_arith.all;

ENTITY hw_image_generator IS
--  GENERIC(
--    
-- row : INTEGER := 15;
-- col : INTEGER := 5;
--	col_a : INTEGER := 80;
--	col_b : INTEGER := 160;
--	col_c : INTEGER := 240;
--	col_d : INTEGER := 320;
--	col_e : INTEGER := 400;
--	col_f : INTEGER := 480;
--	col_g : INTEGER := 560;
--	col_h : INTEGER := 640
--
--	);  
  PORT(
	 Clocking : IN STD_LOGIC;  -- Clock
	 DT :  INOUT   STD_LOGIC; -- ARDUINO_IO6
	 CLK :  INOUT   STD_LOGIC; --ARDUINO_IO7
	 disp_ena :  IN   STD_LOGIC;  --display enable ('1' = display time, '0' = blanking time)
    row      :  IN   INTEGER;    --row pixel coordinate
    column   :  IN   INTEGER;    --column pixel coordinate
    red      :  out  STD_LOGIC_VECTOR(3 DOWNTO 0) := (OTHERS => '0');  --red magnitude output to DAC
    green    :  out  STD_LOGIC_VECTOR(3 DOWNTO 0) := (OTHERS => '0');  --green magnitude output to DAC
    blue     :  out  STD_LOGIC_VECTOR(3 DOWNTO 0) := (OTHERS => '0')); --blue magnitude output to DAC
END hw_image_generator;

ARCHITECTURE behavior OF hw_image_generator IS

signal CLK_i : std_logic; --initial state of clock input
signal counter_u : integer := 210; --paddle position top

BEGIN
  
  
  PROCESS(disp_ena, row, column, counter_u)
  variable counter_l : integer := 270; --paddle position bottom
  BEGIN
	counter_l := counter_u + 60; --paddle width
	--pong display
    IF(disp_ena = '1') THEN        --display time
		if(row < 10 or row > 470) then
			green <= (others => '1');
			red <= (others => '1');
			blue <= (others => '1');
		elsif(column < 330 and column > 310) then
			if(row > 30 and row < 65) then
				green <= (others => '1');
				red <= (others => '1');
				blue <= (others => '1');
			elsif(row > 85 and row < 120) then
				green <= (others => '1');
				red <= (others => '1');
				blue <= (others => '1');
			elsif(row > 140 and row < 175) then
				green <= (others => '1');
				red <= (others => '1');
				blue <= (others => '1');
			elsif(row > 195 and row < 230) then
				green <= (others => '1');
				red <= (others => '1');
				blue <= (others => '1');
			elsif(row > 250 and row < 285) then
				green <= (others => '1');
				red <= (others => '1');
				blue <= (others => '1');
			elsif(row > 305 and row < 340) then
				green <= (others => '1');
				red <= (others => '1');
				blue <= (others => '1');
			elsif(row > 360 and row < 395) then
				green <= (others => '1');
				red <= (others => '1');
				blue <= (others => '1');
			elsif(row > 415 and row < 450) then
				green <= (others => '1');
				red <= (others => '1');
				blue <= (others => '1');
			else
				green <= (others => '0');
				red <= (others => '0');
				blue <= (others => '0');
			end if;
		--affecting the paddle
		elsif(column < 10 or column > 630) then
			--edit these columns using the rotary encoder.
			if(row > counter_u and row < counter_l) then
				green <= (others => '1');
				red <= (others => '1');
				blue <= (others => '1');
			else
				green <= (others => '0');
				red <= (others => '0');
				blue <= (others => '0');
			end if;
		else 
			green <= (others => '0');
			red <= (others => '0');
			blue <= (others => '0');
		end if;
    ELSE                           --blanking time
      green <= (others => '0');
		red <= (others => '0');
		blue <= (others => '0');
    END IF;
  END PROCESS;
  
  
  process(Clocking, CLK, DT)
  Variable count: integer := 0;
  begin	
	if (rising_edge(Clocking)) then
		--debouncing if condition
		if(count > 999) then 
			count := 0;
			--could add boundry check up here instead to reduce description
			--check state and direction of rotary encoder/paddle
			if(CLK /= CLK_i) then
				--left = up
				if(DT /= CLK) then
					if(counter_u > 410) then
						counter_u <= 411;
					else
						counter_u <= counter_u + 8; 
					end if;
				--right = down
				else
					if(counter_u < 10) then
						counter_u <= 9;
					else
						counter_u <= counter_u - 8; 
					end if;
				end if;
			else
				if(counter_u > 410) then
						counter_u <= 411;
				elsif(counter_u < 10) then
						counter_u <= 9;
				else
					counter_u <= counter_u;
				end if;
			end if;
			CLK_i <= CLK;
		else
			count := count + 1;
		end if;
	end if;
  end process;
  

END behavior;
