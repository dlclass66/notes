awk 'NR > 1 {V += $5; R += $6} END{print "MEM TOTAL\nVSZ_SUM:" V / 1024 "M," "RSS_SUM:" R / 1024 "M"}' nowcoder.txt
'要求 获取第二行以后的内容 并计算第五列和第六列的和（要求的命令的和） 以及最后打印总和（end表示只在文本读取完成后执行一次）'
