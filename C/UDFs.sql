DECLARE EXTERNAL FUNCTION Factorial
integer
returns
integer by value
entry_point 'factorial' module_name 'ExtFuns';

DECLARE EXTERNAL FUNCTION Ping
CSTRING(255)
returns integer by value
entry_point 'ping' module_name 'Ping';


DECLARE EXTERNAL FUNCTION Pmt
DOUBLE PRECISION, INTEGER, DOUBLE PRECISION
returns DOUBLE PRECISION by value
entry_point 'pmt' module_name 'ExtFuns';

DECLARE EXTERNAL FUNCTION Bin2Dec	
INTEGER
returns INTEGER by value
entry_point 'bin2dec' module_name 'ExtFuns';

DECLARE EXTERNAL FUNCTION Dec2Bin	
INTEGER
returns INTEGER by value
entry_point 'dec2bin' module_name 'ExtFuns';

DECLARE EXTERNAL FUNCTION C2F	
DOUBLE PRECISION
returns DOUBLE PRECISION by value
entry_point 'c2f' module_name 'ExtFuns';

DECLARE EXTERNAL FUNCTION F2C	
DOUBLE PRECISION
returns DOUBLE PRECISION by value
entry_point 'f2c' module_name 'ExtFuns';

DECLARE EXTERNAL FUNCTION Hex2Dec	
CSTRING(255)
returns INTEGER by value
entry_point 'hex2dec' module_name 'ExtFuns';

DECLARE EXTERNAL FUNCTION Dec2Hex	
INTEGER
returns CSTRING(25)
entry_point 'dec2hex' module_name 'ExtFuns';

DECLARE EXTERNAL FUNCTION CMPRSTR	
CSTRING(255), CSTRING(255)
returns INTEGER by value
entry_point 'compare_string' module_name 'ExtFuns';

DECLARE EXTERNAL FUNCTION TRIMIT
CSTRING(25), CSTRING(1)
returns CSTRING(25)
entry_point 'trim' module_name 'ExtFuns';

DECLARE EXTERNAL FUNCTION REPEAT
CSTRING(50), INTEGER
returns CSTRING(50)
entry_point 'repeat' module_name 'ExtFuns';