package body TemperatureControl is

   procedure StartSetLevel(Start_Level_Tank_101 : in out Float;
                           Stop_Level_Tank_101  : out Float) is
   begin
      -- desired tank level is start tank level + 1.5 L
      Stop_Level_Tank_101 := Start_Level_Tank_101 + 1.5;
      -- open valve 102
      Ball_Valve_V102 := True;
      -- Ball_Valve_V102.set(True);
      -- code and update outputs
      Code_Outputs; -- uncomment in real-time
      UpdateOutputs; -- uncomment in real-time
   end StartSetLevel;


   -- The loop should be set and valve needs to be closed
   procedure StopSetLevel is
   begin
      -- close valve 102
      Ball_Valve_V102 := False;
      -- Ball_Valve_V102.set(False); -- uncomment in real-time
      -- code and update outputs
      -- Code_Outputs; -- uncomment in real-time
      -- UpdateOutputs; -- uncomment in real-time
   end StopSetLevel;

   procedure SetTemperature(Current_Temperature : in out Float) is
   begin
      null;
      -- read current temperature variable
      -- Current_Temperature := Temperature_Tank_B104.get(); -- read temp from the sensor and write it  to the variable
   end SetTemperature;

   -- start the heating the tank needs 23 degree which is set point temp
   procedure StartHeating is
   begin
      -- turn heating on
      Heating_Tank_101 := True;
      -- Heating_Tank_101.set(True);-- uncomment in real-time
      -- code and update outputs
      -- Code_Outputs; -- uncomment in real-time
      -- UpdateOutputs; -- uncomment in real-time
   end StartHeating;

   -- stop the heating when the temp is more than set poin temp which is 23 degrees
   procedure StopHeating is
   begin
      -- turn heating off
      Heating_Tank_101 := False;
      -- Heating_Tank_101.set(False); -- uncomment in real-time
      -- code and update outputs
      Code_Outputs; -- uncomment in real-time
      UpdateOutputs; -- uncomment in real-time
   end StopHeating;
end TemperatureControl;
