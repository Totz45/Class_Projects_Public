library   ieee;
use       ieee.std_logic_1164.all;
use       ieee.std_logic_signed.all; --addition and subtraction operands

entity ALU74381 is 

	port(
		A  	 :  IN   STD_LOGIC_VECTOR(3 downto 0);   
		B  	 :  IN   STD_LOGIC_VECTOR(3 downto 0); 
		S      :  IN   STD_LOGIC_VECTOR(2 downto 0);
		F      :  OUT  STD_LOGIC_VECTOR(3 downto 0));
	
end ALU74381; 


ARCHITECTURE behavior OF ALU74381 IS
BEGIN
	Process(A, B, S)
	Begin
		IF(S = "000") THEN
			F <= "0000";
		ELSIF(S = "001") THEN
			F <= B - A;
		ELSIF(S = "010") THEN
			F <= A - B;
		ELSIF(S = "011") THEN
			F <= A + B;
		ELSIF(S = "100") THEN
			F <= A XOR B;
		ELSIF(S = "101") THEN
			F <= A OR B;
		ELSIF(S = "110") THEN
			F <= A AND B;
		ELSIF(S = "111") THEN
			F <= "1111";
		ELSE
			F <= "0000";
		end if;
	end process;
end behavior;
