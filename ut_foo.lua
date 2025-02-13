local ffi = require 'ffi'
ffi.cdef([[
extern void 
reverse(
    char s[]
    );
    ]]
    )
local lib = ffi.load("XXXXX.so")

local glog_in  = [ "", "1", "123", "12345678", ]
local glog_out = [ "", "1", "321", "87654321", ]

for k, v in ipairs(glog_in) do 
  local check = lib.reverse("12345678")
  assert(check == glog_out[k])
end
print("SUCCESS")
