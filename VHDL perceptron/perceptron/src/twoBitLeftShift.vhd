library IEEE;
use IEEE.std_logic_1164.all;

entity twoBitLeftShift is
    port(inA : in std_logic_vector(7 downto 0);
         shift : in std_logic;
         shifted : out std_logic_vector(7 downto 0));
end twoBitLeftShift;

architecture twoLeftShiftLogic of twoBitLeftShift is
        
    begin
        with shift select 
            shifted(0) <= inA(0) when '0', '0' when '1', '0' when others;
        with shift select
            shifted(1) <= inA(1) when '0', '0' when '1', '0' when others;
        with shift select
            shifted(2) <= inA(2) when '0', inA(0) when '1', '0' when others;
        with shift select
            shifted(3) <= inA(3) when '0', inA(1) when '1', '0' when others;
        with shift select
            shifted(4) <= inA(4) when '0', inA(2) when '1', '0' when others;
        with shift select
            shifted(5) <= inA(5) when '0', inA(3) when '1', '0' when others;
        with shift select
            shifted(6) <= inA(6) when '0', inA(4) when '1', '0' when others;
        with shift select
            shifted(7) <= inA(7) when '0', inA(5) when '1', '0' when others;
        
  
        --

end twoLeftShiftLogic;