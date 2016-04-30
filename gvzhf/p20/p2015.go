package main

import "fmt"

func main() {
	var myMoney, singleApAdv, doubleApAdv int
	var n, m int
	var friendMoney [256]int
	var friendAdvantages [256]int
	fmt.Scan(&myMoney)
	fmt.Scan(&singleApAdv)
	fmt.Scan(&doubleApAdv)

	fmt.Scan(&n)
	for i := 0; i < n; i++ {
		fmt.Scan(&friendMoney[i])
		fmt.Scan(&friendAdvantages[i])
	}

	var maxAdv, maxFriend, maxAp int
	maxAdv = -1
	maxFriend = -1
	maxAp = -1

	fmt.Scan(&m)
	for i := 0; i < m; i++ {
		var apRooms, apMoney, apAdv int
		fmt.Scan(&apRooms)
		fmt.Scan(&apMoney)
		fmt.Scan(&apAdv)
		if apRooms == 1 {
			if apMoney <= myMoney && apAdv+singleApAdv > maxAdv {
				maxAdv = apAdv + singleApAdv
				maxFriend = -1
				maxAp = i
			}
		} else {
			if apMoney <= myMoney && apAdv+doubleApAdv > maxAdv {
				maxAdv = apAdv + doubleApAdv
				maxFriend = -1
				maxAp = i
			}
			for j := 0; j < n; j++ {
				if apMoney <= 2*myMoney && apMoney <= 2*friendMoney[j] && apAdv+friendAdvantages[j] > maxAdv {
					maxAdv = apAdv + friendAdvantages[j]
					maxFriend = j
					maxAp = i
				}
			}
		}
	}

	if maxAdv < 0 {
		fmt.Printf("Forget about apartments. Live in the dormitory.\n")
	} else if maxFriend < 0 {
		fmt.Printf("You should rent the apartment #%v alone.\n", maxAp+1)
	} else {
		fmt.Printf("You should rent the apartment #%v with the friend #%v.\n", maxAp+1, maxFriend+1)
	}
}

