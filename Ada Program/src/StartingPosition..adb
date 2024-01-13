package body StartingPosition is


   -- Procedure for filling the Tank
   procedure FillingTank is
   begin
      -- Opens the Ball_Valve_V102 as per requirment
      Ball_Valve_V102 := True;
      -- Code and update outputs, for testing commented, uncomment on real-time
      -- Code_Outputs; -- Uncomment this line
      -- UpdateOutputs; -- Uncomment this line
   end FillingTank;


   procedure StopFillingTank is
   begin -- structure identical to FillinngTank but close the  valve
      -- close the Ball_Valve_V102
      Ball_Valve_V102 := False;

      -- code and update outputs
      -- Code_Outputs; --Uncomment
      -- UpdateOutputs; --Uncomment
   end StopFillingTank;

   procedure CreateStart is
   begin
      -- check if Valve V102 is closed
      if Ball_Valve_V102 then -- check if Value V102 is True
         --set the analog value and open valve V106
         Proportional_Valve_V106_Analog := 100.0; -- First, Analog Value 100 Fully opens the valve, in analog mode
         Proportional_Valve_V106 := True; -- This indicates that valve is opened, , in digital mode
         -- turn on pump 101
         Pump_P101 := True; -- Pump is turned on
         -- code and upate outputs
         --Code_Outputs; --Uncomment on Real-time
         --UpdateOutputs; --Uncomment on Real-time
      end if;
   end CreateStart;

   procedure StopStart(Create_Start: in out Boolean; Start_Created: in out
                         Boolean) is
   begin
      -- turn off valve 106 and pump 101
      Proportional_Valve_V106 := False; -- Valve turned off
      Pump_P101 := False; --  Pump turned off
      -- code and update outputs
      --Code_Outputs; --Uncomment in Real-Time
      --UpdateOutputs; --Uncomment in Real-Time
      Create_Start := True;
      Start_Created := True;
   end StopStart;

end StartingPosition;


