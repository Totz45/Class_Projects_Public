How to assemble
-- the MAX 10: 10M50DAF484C7G was used to test program
-- connect DT on rotary encoder to ARDUINO_IO6 on board
-- connect CLK on rotary encoder to ARDUINO_IO7 on board
-- provide ground and 5V power to repective pins on rotary encoder
-- include all VHD files with project
-- pin assignments in the assignment editor should be made using the provided PE2.qsf file as reference
-- an example video attached to submission shows expected output if configured properly


Notes
-- tested PE2.qpf with only vhd and qsf and compiles fine on my computer.
-- not sure about others as I haven't gotten grades back on the homework assignments that implemented this method.

References and IP used
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