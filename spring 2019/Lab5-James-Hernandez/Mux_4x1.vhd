library ieee;
use ieee.std_logic_1164.all;

entity Mux_4x1 is
port(op: in std_logic_vector (1 downto 0);
     x1: in std_logic;
     x2: in std_logic;
     x3: in std_logic;
	 x4: in std_logic;
	  
     y:  out std_logic
      );
end Mux_4x1;

architecture struct of Mux_4x1 is

   --use previously designed subcomponents
   
 
	
  component AND_gate is
   port( x: in std_logic;
         y: in std_logic;
         z: out std_logic
        );
   end component;
   
 

   component OR_gate is
   port( x: in std_logic;
         y: in std_logic;
         z: out std_logic
        );
	
   end component;
   
  component Decoder_4 is
  port(x1: in std_logic;
      x2: in std_logic;
      y1: out std_logic;
	  y2: out std_logic;
	  y3: out std_logic;
	  y4: out std_logic

  );
  end component;
    

   signal temp1: std_logic; --to store the output of the not gate
   signal temp2: std_logic;--to store the output of and1 gate
   signal temp3: std_logic;--to store the output of and2 gate
   signal temp4: std_logic;
   signal temp5: std_logic;
   signal temp6: std_logic;
   signal temp7: std_logic;
   signal temp8: std_logic;
   signal temp9: std_logic;
   signal temp10: std_logic;
  
   
  
begin
   
   --map signals of the outer component to subcomponents - idea of parameter passing
   
   map_Decoder_4: Decoder_4 port map (op(1),op(0), temp1,temp2,temp3,temp4);
   map_AND_gate1: AND_gate port map (x1, temp1, temp5);
   map_AND_gate2: AND_gate port map (x2, temp2, temp6); 
   map_AND_gate3: AND_gate port map (x3, temp3, temp7);
   map_AND_gate4: AND_gate port map (x4, temp4, temp8);
   map_OR_gate1:  OR_gate port map (temp5,temp6, temp9); 
   map_OR_gate2:  OR_gate port map (temp7,temp8, temp10); 
   map_OR_gate3:  OR_gate port map (temp9,temp10, y); 
   

end struct;
