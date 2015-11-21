#include <iostream>
int main() {
	int n, k, t, not_used=0, alive_droids=0;
	std::cin >> n >> k;
	for(int i = 0; i<n; i++){
		std::cin >> t;
		if(t>k)
			not_used+=t-k;
		else
			alive_droids+=k-t;
	}
	std::cout << not_used << " " << alive_droids << std::endl;
	return 0;
}
