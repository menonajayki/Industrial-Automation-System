with Ada.Text_IO; use Ada.Text_IO;
with Ada.Integer_Text_IO; use Ada.Integer_Text_IO;

procedure Multiple_Task_Execution_Example is
   task Repeated_Task;
   task body Repeated_Task is
   begin
      for I in 1 .. 5 loop -- Execute the task 5 times
         Put("Task execution number : ");
         Put(Integer'Image(I));
         New_Line;
         -- Task instructions here
      end loop;
   end Repeated_Task;
begin
   null;
end Multiple_Task_Execution_Example;
