myprint = function(param)
	print("这是打印函数 - ##",param,"##")
end

function add(num1,num2,functionPrint)
	result = num1 + num2
	functionPrint(result)
end

myprint(10)

add (7,8,myprint)
