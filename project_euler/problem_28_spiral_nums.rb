# Problem 28 Spiral Numbers

i = 3
k = 1
res = 0
for j in 1 .. 2000
  res += i
  if (j % 4) == 0
    k += 1
  end
  i += (2*k)
end
puts res + 1
