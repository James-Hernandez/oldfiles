library ieee;
use ieee.std_logic_1164.all;

entity OneBit_Adder_TB is
end OneBit_Adder_TB;

architecture TB of OneBit_Adder_TB is

   --the component we are testing is AND_OR
   component OneBit_Adder is
   port( x1: in std_logic;
         x2: in std_logic;
         x3: in std_logic;
         y1: out std_logic;
		 y2: out std_logic
        );
   end component;

   signal a1, a2, a3, b, c: std_logic;

   begin
      test_OneBit_Adder: OneBit_Adder port map (a1, a2, a3, b, c);

   process 
      begin
         --case1
         a1 <= '0';
         a2 <= '0';
         a3 <= '0';
		 
         wait for 10 ns;
         assert (b = '0') and (c = '0');
		 report "case1 failed!" severity error;
         
		 --case2
         a1 <= '0';
         a2 <= '0';
         a3 <= '1';
		 wait for 10 ns;
		assert (b = '1') and (c = '0');
		 report "case2 failed!" severity error;
		
        
		--case3
         a1 <= '0';
         a2 <= '1';
         a3 <= '0';
		 wait for 10 ns;
         assert (b = '1') and (c = '0');
		 report "case3 failed!" severity error;
         
         --case4
         a1 <= '0';
         a2 <= '1';
         a3 <= '1';
		 wait for 10 ns;
        assert (b = '0') and (c = '1');
		 report "case4 failed!" severity error;

         --case5
         a1 <= '1';
         a2 <= '0';
         a3 <= '0';
		wait for 10 ns;
         assert (b = '1') and (c = '0');
		 report "case5 failed!" severity error;

         --case6
         a1 <= '1';
         a2 <= '0';
         a3 <= '1';
		 wait for 10 ns;
         assert (b = '0') and (c = '1');
		 report "case6 failed!" severity error;

         --case7
         a1 <= '1';
         a2 <= '1';
         a3 <= '0';
		 wait for 10 ns;
		 assert (b = '0') and (c = '1');
		 report "case7 failed!" severity error;
         

         --case8
         a1 <= '1';
         a2 <= '1';
         a3 <= '1';
		 wait for 10 ns;
         assert (b = '1') and (c = '1');
		 report "case8 failed!" severity error;

         wait;
   end process;
end TB;

configuration CFG_TB of OneBit_Adder_TB is 
   for TB
   end for;
end CFG_TB; --or, lower case is OK (end cfg_TB)
