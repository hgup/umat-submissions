Hospital Management System in C.
A system designed using C uniquely for storing all the patient related information.
This system allows users to add, display, edit, and search for patient information.
Additionally, it provides functionalities like deleting patient records, searching patients by name, surname, admit date, doctor, or ID,
revisiting patients, sorting patients by admit date, and updating credentials and login.

Here's a summary of the functionalities provided by the code:

Add Patient: Allows users to add patient information, including name, age, gender, father's name, contact details, address, disease, and doctor.
Display Patients: Displays the information of all the patients stored in the file.
Delete Patient: Deletes a patient record based on the provided ID.

Search Patient by Name: Searches for patients based on their name.
Search Patient by Surname: Searches for patients based on their surname.
Search Patient by Admit Date: Searches for patients based on their admit date.
Search Patient by Doctor: Searches for patients based on the doctor's name.
Search Patient by ID: Searches for a patient based on their ID.

Edit Patient: Allows users to edit patient information based on their ID.
Revisit Patient: Records revisit information for a patient based on their ID.
Sort Patients by Admit Date: Sorts the patients' records based on their admit date.
Update Credentials: Allows updating of system login credentials.

Additionally, the code includes some helper functions for input validation and managing patient records.

First of all user has to create "login.txt" and "patient.txt" files in your system and then compile it.
User has to create username and password for first time and directly it will open. 
The username and password we created will be used further for updating credentials later.
If it is not the first time user has to login ,user will have only 3 attempts.
After successful login, user can able to see the main menu having all the above mentioned functions in it,including updating credentials.
After the completion of work, user can exit by selecting the exit option from main menu.