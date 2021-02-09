library ieee;
use ieee.std_logic_1164.all;

entity OneBit_ALU_TB is
end OneBit_ALU_TB;

architecture TB of OneBit_ALU_TB is

   --the component we are testing is AND_OR
   component OneBit_ALU is
   port( x1: in std_logic;--a
         x2: in std_logic;--b
         x3: in std_logic;--cin
	     x4: in std_logic_vector(1 downto 0);--control 1
	  
         y1: out std_logic;--cout
	     y2: out std_logic--result
        );
   end component;

   signal a1, a2, a3, b, c: std_logic;
   signal a4: std_logic_vector (1 downto 0);
   begin
      test_OneBit_ALU: OneBit_ALU port map (a1, a2, a3, a4, b, c);

   process 
      begin
         --case1
         a1 <= '0';
         a2 <= '0';
         a3 <= '0';
		 a4 <= "00";
		 --a5 <= '0';
         wait for 10 ns;
         
         --case2
         a1 <= '0';
         a2 <= '0';
         a3 <= '1';
		 a4 <= "00";
		 --a5 <= '0';
         wait for 10 ns;
		 
         --case3
         a1 <= '0';
         a2 <= '1';
         a3 <= '0';
		 a4 <= "00";
		-- a5 <= '0';
         wait for 10 ns;
		 
         --case4
         a1 <= '0';
         a2 <= '1';
         a3 <= '1';
		 a4 <= "00";
		-- a5 <= '0';
         wait for 10 ns;
		 
         --case5
         a1 <= '1';
         a2 <= '0';
         a3 <= '0';
		 a4 <= "00";
		-- a5 <= '0';
         wait for 10 ns;
		 
         --case6
         a1 <= '1';
         a2 <= '0';
         a3 <= '1';
		 a4 <= "00";
		-- a5 <= '0';
         wait for 10 ns;
		 
         --case7
         a1 <= '1';
         a2 <= '1';
         a3 <= '0';
		 a4 <= "00";
		 --a5 <= '0';
         wait for 10 ns;
		 
         --case8
         a1 <= '1';
         a2 <= '1';
         a3 <= '1';
		 a4 <= "00";
		 --a5 <= '0';
         wait for 10 ns;
		 
		 --case9
         a1 <= '0';
         a2 <= '0';
         a3 <= '0';
		 a4 <= "01";
		 --a5 <= '1';
         wait for 10 ns;
         
         --case10
         a1 <= '0';
         a2 <= '0';
         a3 <= '1';
		 a4 <= "01";
		 --a5 <= '1';
         wait for 10 ns;
		 
         --case11
         a1 <= '0';
         a2 <= '1';
         a3 <= '0';
		 a4 <= "01";
		-- a5 <= '1';
         wait for 10 ns;
		 
         --case12
         a1 <= '0';
         a2 <= '1';
         a3 <= '1';
		 a4 <= "01";
		 --a5 <= '1';
         wait for 10 ns;
		 
         --case13
         a1 <= '1';
         a2 <= '0';
         a3 <= '0';
		 a4 <= "01";
		 --a5 <= '1';
         wait for 10 ns;
		 
         --case14
         a1 <= '1';
         a2 <= '0';
         a3 <= '1';
		 a4 <= "01";
		 --a5 <= '1';
         wait for 10 ns;
		 
         --case15
         a1 <= '1';
         a2 <= '1';
         a3 <= '0';
		 a4 <= "01";
		 --a5 <= '1';
         wait for 10 ns;
		 
         --case16
         a1 <= '1';
         a2 <= '1';
         a3 <= '1';
		 a4 <= "01";
		 --a5 <= '1';
         wait for 10 ns;
		 
		 --case17
         a1 <= '0';
         a2 <= '0';
         a3 <= '0';
		 a4 <= "00";
		 --a5 <= '0';
         wait for 10 ns;
         
         --case18
         a1 <= '0';
         a2 <= '0';
         a3 <= '1';
		 a4 <= "10";
		 --a5 <= '0';
         wait for 10 ns;
		 
         --case19
         a1 <= '0';
         a2 <= '1';
         a3 <= '0';
		 a4 <= "10";
		 --a5 <= '0';
         wait for 10 ns;
		 
         --case20
         a1 <= '0';
         a2 <= '1';
         a3 <= '1';
		 a4 <= "10";
		 --a5 <= '0';
         wait for 10 ns;
		 
         --case21
         a1 <= '1';
         a2 <= '0';
         a3 <= '0';
		 a4 <= "10";
		 --a5 <= '0';
         wait for 10 ns;
		 
         --case22
         a1 <= '1';
         a2 <= '0';
         a3 <= '1';
		 a4 <= "10";
		 --a5 <= '0';
         wait for 10 ns;
		 
         --case23
         a1 <= '1';
         a2 <= '1';
         a3 <= '0';
		 a4 <= "10";
		 --a5 <= '0';
         wait for 10 ns;
		 
         --case24
         a1 <= '1';
         a2 <= '1';
         a3 <= '1';
		 a4 <= "10";
		 --a5 <= '0';
         wait for 10 ns;
		 
		 --case25
         a1 <= '0';
         a2 <= '0';
         a3 <= '0';
		 a4 <= "11";
		 --a5 <= '1';
         wait for 10 ns;
         
         --case26
         a1 <= '0';
         a2 <= '0';
         a3 <= '1';
		 a4 <= "11";
		 --a5 <= '1';
         wait for 10 ns;
		 
         --case27
         a1 <= '0';
         a2 <= '1';
         a3 <= '0';
		 a4 <= "11";
		 --a5 <= '1';
         wait for 10 ns;
		 
         --case28
         a1 <= '0';
         a2 <= '1';
         a3 <= '1';
		 a4 <= "11";
		 --a5 <= '1';
         wait for 10 ns;
		 
         --case29
         a1 <= '1';
         a2 <= '0';
         a3 <= '0';
		 a4 <= "11";
		 --a5 <= '1';
         wait for 10 ns;
		 
         --case30
         a1 <= '1';
         a2 <= '0';
         a3 <= '1';
		 a4 <= "11";
		 --a5 <= '1';
         wait for 10 ns;
		 
         --case31
         a1 <= '1';
         a2 <= '1';
         a3 <= '0';
		 a4 <= "11";
		 --a5 <= '1';
         wait for 10 ns;
		 
         --case32
         a1 <= '1';
         a2 <= '1';
         a3 <= '1';
		 a4 <= "11";
		 --a5 <= '1';
         wait for 10 ns;
         wait;
   end process;
end TB;

configuration CFG_TB of OneBit_ALU_TB is 
   for TB
   end for;
end CFG_TB; --or, lower case is OK (end cfg_TB)
