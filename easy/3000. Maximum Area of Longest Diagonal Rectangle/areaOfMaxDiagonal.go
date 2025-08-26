func areaOfMaxDiagonal(dimensions [][]int) int {
	diagSq, area := -1, -1
	for _, rec := range dimensions {
		nowDiagSq := rec[0]*rec[0] + rec[1]*rec[1]
		if nowDiagSq > diagSq {
			diagSq = nowDiagSq
			area = rec[0] * rec[1]
		} else if nowDiagSq == diagSq {
			area = max(area, rec[0]*rec[1])
		}
	}
	return area
}