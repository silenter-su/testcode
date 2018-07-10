#!/usr/local/bin/lua



--单行注释
--[[
多
行
注
释
--]]




print("hello lua.")
print(b)
b=10
print(b)





tab1 = { key1 = "val1", "val2", key3 = "val3","val4" }
for k, v in pairs(tab1) do
    print(k .. " - " .. v)
end
 
tab1.key1 = nil
for k, v in pairs(tab1) do
    print(k .. " - " .. v)
end
