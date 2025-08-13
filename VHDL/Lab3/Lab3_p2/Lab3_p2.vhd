library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Lab3_p2 is
    generic (dp_width : integer := 32); -- Width of the multiplier
    Port ( Clock, Reset : in STD_LOGIC;
           divisor : in STD_LOGIC_VECTOR (dp_width-1 downto 0);
			  remainder_in : in STD_LOGIC_VECTOR (2*dp_width-1 downto 0);
			  quotient : out STD_LOGIC_VECTOR (dp_width-1 downto 0);
           remainder_out : out STD_LOGIC_VECTOR (2*dp_width-1 downto 0);
           start : in STD_LOGIC;
           ready : out STD_LOGIC);
end Lab3_p2;

architecture Structural of Lab3_p2 is
    signal load_sig, sub_sig : STD_LOGIC;
	 signal shiftQ_sig, shiftR_sig : STD_LOGIC;
    signal internal_start, internal_done : STD_LOGIC;
	 
	 component Controller
        Port ( clk, rst, start, multi_done : in STD_LOGIC;
               load_reg, sub_reg, shiftQ_reg, shiftR_reg : out STD_LOGIC);
    end component;
    
	 component Datapath
        generic (dp_width : integer := 32);
        Port ( clock, reset, load, sub, shiftQ, shiftR : in STD_LOGIC;
               quotient : out STD_LOGIC_VECTOR (dp_width-1 downto 0);
					divisor : in STD_LOGIC_VECTOR (dp_width-1 downto 0);
               remainder_in : in STD_LOGIC_VECTOR ((2*dp_width)-1 downto 0);
					remainder_out : out STD_LOGIC_VECTOR ((2*dp_width)-1 downto 0);
               start, done : out STD_LOGIC);
    end component;

begin
    DUT1 : Controller Port map (Clock, Reset, start, internal_done, load_sig, sub_sig, shiftQ_sig, shiftR_sig);

    DUT2 : Datapath Generic map (dp_width => 32) 
							Port map (Clock, Reset, load_sig, sub_sig, shiftQ_sig, shiftR_sig, quotient, divisor, remainder_in, remainder_out, internal_start,internal_done);

    -- Connect internal signals
    internal_start <= start;

    -- Output done signal
    ready <= internal_done;

end Structural;