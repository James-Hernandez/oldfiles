library ieee;
use ieee.std_logic_1164.all;

entity Decoder_4_TB is
end Decoder_4_TB;

architecture TB of Decoder_4_TB is

   --the component we are testing is AND_OR
   component Decoder_4 is
   port( x1: in std_logic;
         x2: in std_logic;
         y1: out std_logic;
		 y2: out std_logic;
		 y3: out std_logic;
		 y4: out std_logic
        );
   end component;

   signal a1, a2, a, b, c, d: std_logic;

   begin
      test_Decoder_4: Decoder_4 port map (a1, a2, a, b, c, d);

   process 
      begin
         --case1
         a1 <= '0';
         a2 <= '0';
         --a <= '1';
		 --b <= '0';
		 --c <= '0';
		 --d <= '0';
		 
         wait for 10 ns;
         --assert (b = '0') and (c = '0');
		 --report "case1 failed!" severity error;
         
		 --case2
         a1 <= '0';
         a2 <= '1';
         --a <= '0';
		 --b <= '1';
		 --c <= '0';
		 --d <= '0';
		 wait for 10 ns;
		--assert (b = '1') and (c = '0');
		 --report "case2 failed!" severity error;
		
        
		--case3
         a1 <= '1';
         a2 <= '0';
         --a <= '0';
		 --b <= '0';
		 --c <= '1';
		 --d <= '0';
		 wait for 10 ns;
         --assert (b = '1') and (c = '0');
		 --report "case3 failed!" severity error;
         
         --case4
         a1 <= '1';
         a2 <= '1';
         --a <= '0';
		 --b <= '0';
		 --c <= '0';
		 --d <= '1';
		 wait for 10 ns;
        --assert (b = '0') and (c = '1');
		 --report "case4 failed!" severity error;

        
         wait;
   end process;
end TB;

configuration CFG_TB of Decoder_4_TB is 
   for TB
   end for;
end CFG_TB; --or, lower case is OK (end cfg_TB)
