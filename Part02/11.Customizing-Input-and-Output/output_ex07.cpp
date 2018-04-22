
modify the program from the previous exercise so that it replaces do not with 
do not cannot with cannot etc leaves hyphens within words intact so that 
we get "do not use the as if rule" and converts all characters to lower 
case 

include "std lib facilities h" 

int main 

string filename 
cout "input a filename " 
cin filename 

ifstream ifs filename 
if ifs error "could not open file for read " filename 

ofstream ofs string "output " filename 
if ofs error "could not write to output file " 

ostringstream oss 

while ifs 
string line 
getline ifs line 

for char ch line 
ch tolower ch 
if ch ' "' ch ' '' ispunct ch 
oss ch 
else 
oss ' ' 



oss ' n' 


istringstream iss oss str 

while iss 
string line 
getline iss line 

istringstream issline line 
for string word issline word 
if word "don't" word "do not" 
if word "can't" word "cannot" 
if word "wouldn't" word "woudl not" 
if word "couldn't" word "could not" 
if word "doesn't" word "does not" 
if word "weren't" word "were not" 
if word "wasn't" word "was not" 
if word "haven't" word "have not" 
if word "hasn't" word "has not" 
if word "isn't" word "is not" 
if word "aren't" word "are not" 
ofs word " " 

ofs ' n' 



cout "file written successfully n" 

return 0 



