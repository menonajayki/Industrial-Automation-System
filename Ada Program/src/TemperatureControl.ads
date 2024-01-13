package TemperatureControl is
   procedure StartSetLevel(Start_Level_Tank_101 : in out Float; Stop_Level_Tank_101: out
                             Float);
   procedure StopSetLevel;
   procedure SetTemperature(Current_Temperature : in out Float);
   procedure StartHeating;
   procedure StopHeating;
end;
