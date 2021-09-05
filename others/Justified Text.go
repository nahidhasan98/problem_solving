#include<>

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	if scanner.Scan() {
		var s string
		s = scanner.Text()

		s = strings.TrimSpace(s)

		var reg = regexp.MustCompile(`[ ]{2,}`)
		s = reg.ReplaceAllString(s, " ")

		list := strings.Split(s, " ")

		for i := 0; i < len(list); i++ {
			if len(list[i]) > 8 {
				list[i] = "#bigword"
			}
		}

		fmt.Printf("%s", list[0])
		last := len(list[0])

		for i := 1; i < len(list); i++ {
			if last+1+len(list[i]) <= 8 {
				fmt.Printf(" %s", list[i])
				last += len(list[i]) + 1
			} else {
				fmt.Printf("\n%s", list[i])
				last = len(list[i])
			}
		}
	}
}
