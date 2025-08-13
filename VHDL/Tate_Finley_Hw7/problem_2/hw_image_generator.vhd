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
--passed in clock
ENTITY hw_image_generator IS
   PORT(
    Clock    :  IN	STD_LOGIC;
	 disp_ena :  IN   STD_LOGIC;  --display enable ('1' = display time, '0' = blanking time)
    row      :  IN   INTEGER;    --row pixel coordinate
    column   :  IN   INTEGER;    --column pixel coordinate
    red      :  out  STD_LOGIC_VECTOR(3 DOWNTO 0) := (OTHERS => '0');  --red magnitude output to DAC
    green    :  out  STD_LOGIC_VECTOR(3 DOWNTO 0) := (OTHERS => '0');  --green magnitude output to DAC
    blue     :  out  STD_LOGIC_VECTOR(3 DOWNTO 0) := (OTHERS => '0')); --blue magnitude output to DAC
END hw_image_generator;

ARCHITECTURE behavior OF hw_image_generator IS
  signal green_int : std_logic_vector(3 downto 0);
  signal red_int : std_logic_vector(3 downto 0);
  signal blue_int : std_logic_vector(3 downto 0);
  signal row_mask : integer := 32; 
  signal col_mask : integer := 32; 
  signal bounceR, bounceC : std_logic := '0';
  BEGIN

  
  --change green	
  PROCESS(disp_ena, row, column)
  BEGIN
    IF(disp_ena = '1') THEN        --display time
      --change green
		IF(row < 240) THEN
			green_int(3) <= '1';
		ELSIF(row > 240 and row < 480) THEN
			green_int(3) <= '0';	
		ELSE
			green_int(3) <= '0';
		END IF;
		
		IF(column < 80) then
			green_int(2 downto 0) <= "111";
		ELSIF(column < 160 and column > 80) then
			green_int(2 downto 0) <= "110";
		ELSIF(column < 240 and column > 160) then
			green_int(2 downto 0) <= "101";
		ELSIF(column < 320 and column > 240) then
			green_int(2 downto 0) <= "100";
		ELSIF(column < 400 and column > 320) then
			green_int(2 downto 0) <= "011";
		ELSIF(column < 480 and column > 400) then
			green_int(2 downto 0) <= "010";
		ELSIF(column < 560 and column > 480) then
			green_int(2 downto 0) <= "001";
		ELSIF(column < 640 and column > 560) then
			green_int(2 downto 0) <= "000";
		ELSE
			green_int(2 downto 0) <= (OTHERS => '0');
		END IF;
	ELSE                           --blanking time
      green_int <= (OTHERS => '0');
    END IF;
  END PROCESS;
  
  --change red and blue
  process(disp_ena, row, column)
  variable num_col : integer := 0;
  variable num_row : integer := 0;
  begin
	IF(disp_ena = '1') THEN
		num_col := column mod 80;
		num_row := row mod 240;
		num_col := num_col/5;
		num_row := num_row/15;
		--red
		if(num_col = 15) then
			red_int <= "0000";
		elsif(num_col = 14) then
			red_int <= "0001";
		elsif(num_col = 13) then
			red_int <= "0010";
		elsif(num_col = 12) then
			red_int <= "0011";
		elsif(num_col = 11) then
			red_int <= "0100";
		elsif(num_col = 10) then
			red_int <= "0101";
		elsif(num_col = 9) then
			red_int <= "0110";
		elsif(num_col = 8) then
			red_int <= "0111";
		elsif(num_col = 7) then
			red_int <= "1000";
		elsif(num_col = 6) then
			red_int <= "1001";
		elsif(num_col = 5) then
			red_int <= "1010";
		elsif(num_col = 4) then
			red_int <= "1011";
		elsif(num_col = 3) then
			red_int <= "1100";
		elsif(num_col = 2) then
			red_int <= "1101";
		elsif(num_col = 1) then
			red_int <= "1110";
		elsif(num_col = 0) then
			red_int <= "1111";
		else
			red_int <= (others => '0');
		end if;
		--blue
		if(num_row = 15) then
			blue_int <= "0000";
		elsif(num_row = 14) then
			blue_int <= "0001";
		elsif(num_row = 13) then
			blue_int <= "0010";
		elsif(num_row = 12) then
			blue_int <= "0011";
		elsif(num_row = 11) then
			blue_int <= "0100";
		elsif(num_row = 10) then
			blue_int <= "0101";
		elsif(num_row = 9) then
			blue_int <= "0110";
		elsif(num_row = 8) then
			blue_int <= "0111";
		elsif(num_row = 7) then
			blue_int <= "1000";
		elsif(num_row = 6) then
			blue_int <= "1001";
		elsif(num_row = 5) then
			blue_int <= "1010";
		elsif(num_row = 4) then
			blue_int <= "1011";
		elsif(num_row = 3) then
			blue_int <= "1100";
		elsif(num_row = 2) then
			blue_int <= "1101";
		elsif(num_row = 1) then
			blue_int <= "1110";
		elsif(num_row = 0) then
			blue_int <= "1111";
		else
			blue_int <= (others => '0');
		end if;
	Else
		blue_int <= (others => '0');
		red_int <= (others => '0');
	end if;
  end process;
  
  process(Clock, row, column, green_int, red_int, blue_int)
  variable min_col, min_row : integer := 0;
  variable max_col, max_row : integer;
  variable counter : integer := 0;
  begin
		max_col := min_col + 32;
		max_row := min_row + 32;
		if(rising_edge(Clock)) then
			if(counter > 999999) then
				counter := 0;
				if(bounceC = '1') then
					min_col := min_col - 1;
				else
					min_col := min_col + 1;
				end if;
				if(bounceR = '1') then
					min_row := min_row - 1;
				else
					min_row := min_row + 1;
				end if;
				
				if(max_row > 480) then
					bounceR <= '1';
				elsif(min_row < 0) then
					bounceR <= '0';
				end if;
				
				if(max_col > 640) then
					bounceC <= '1';
				elsif(min_col < 0) then
					bounceC <= '0';
				end if;
			else
				counter := counter + 1;
			end if;
		end if;
	
		if(row > min_row and row < max_row) then
			if(column > min_col and column < max_col) then
				red <= red_int;
				green <= green_int;
				blue <= blue_int;
			else
				red <= (others => '0');
				green <= (others => '0');
				blue <= (others => '0');
			end if;
		else
			red <= (others => '0');
			green <= (others => '0');
			blue <= (others => '0');
		end if;
  end process;

  
END behavior;
