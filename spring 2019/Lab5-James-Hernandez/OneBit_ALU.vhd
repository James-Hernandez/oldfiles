library ieee;
use ieee.std_logic_1164.all;

entity OneBit_ALU is

port( x1: in std_logic;--a
      x2: in std_logic;--b
      x3: in std_logic;--cin
	  x4: in std_logic_vector(1 downto 0);--control 1
	  
      y1: out std_logic;--cout
	  y2: out std_logic--result
      );
end OneBit_ALU;

architecture struct of OneBit_ALU is

   --use previously designed subcomponents
   
  component OR_gate is
	port( x: in std_logic;
		  y: in std_logic;
	      z: out std_logic
	    );
	end component;
	
  component AND_gate is
   port( x: in std_logic;
         y: in std_logic;
         z: out std_logic
        );
   end component;
   
   component OneBit_Adder is
   port( x1: in std_logic;
         x2: in std_logic;
         x3: in std_logic;
         y1: out std_logic;
	     y2: out std_logic

   
   
   );
   end component;
   
   component Mux_4x1 is
   port(  op: in std_logic_vector (1 downto 0);
          x1: in std_logic;
          x2: in std_logic;
          x3: in std_logic;
	      x4: in std_logic;
	      y:  out std_logic
       );
	end component;
	
   signal temp1: std_logic; --to store the output of the not gate
   signal temp2: std_logic;--to store the output of and1 gate
   signal temp3: std_logic;--to store the output of and2 gate
   signal temp4: std_logic;
   
begin
   
   --map signals of the outer component to subcomponents - idea of parameter passing
  
   map_AND_gate1: AND_gate port map (x1, x2, temp1);
   map_OR_gate1:  OR_gate port map (x1, x2, temp2); --then, temp1 is passed to the OR as an input
   map_OneBit_Adder: OneBit_Adder port map (x1, x2, x3, temp3, y1);
   map_Mux_4x1: Mux_4x1 port map(x4, temp1, '0', temp3,'0', y2);
   

end struct;
