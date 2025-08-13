-- File Name: reg_unit.vhd
-- Author: Tate Finley
-- Purpose: Implementation of registers with read/write capability.

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use work.RegisterPackage.ALL;

entity reg_unit is
    Port (Clock : in STD_LOGIC;
			Reg_write_sig : in STD_LOGIC;
			reg_read_1, reg_read_2, write_reg_1 : in STD_LOGIC_VECTOR(4 downto 0);
			data_write : in STD_LOGIC_VECTOR(31 downto 0);
			read_out_1, read_out_2 : out STD_LOGIC_VECTOR(31 downto 0));
end reg_unit;

architecture reg_arch of reg_unit is
    signal Registers : RegisterArrayType := (others => (others => '0'));

    -- Component declarations
    component ReadUnit
         Port (reg_read_1 : in STD_LOGIC_VECTOR(4 downto 0);
					reg_read_2 : in STD_LOGIC_VECTOR(4 downto 0);
					all_regs_with_data : in RegisterArrayType;
					data_reg1 : out STD_LOGIC_VECTOR(31 downto 0);
					data_reg2 : out STD_LOGIC_VECTOR(31 downto 0));
    end component;

    component WriteUnit
        Port (Clock : in STD_LOGIC;
				reg_write_sig : in STD_LOGIC;
				reg_write_1 : in STD_LOGIC_VECTOR(4 downto 0);
				reg_data : in STD_LOGIC_VECTOR(31 downto 0);
				all_regs_with_data : inout RegisterArrayType);
    end component;

begin
    -- Instantiate Write Unit
    DUT1: WriteUnit port map (Clock, Reg_write_sig, write_reg_1,data_write,Registers);

    -- Instantiate Read Unit
    DUT2: ReadUnit port map (reg_read_1,reg_read_2, Registers,read_out_1, read_out_2);

end reg_arch;
