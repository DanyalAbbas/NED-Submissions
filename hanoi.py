def TowerOfHanoi(n, src, dest, auxi):
    if n == 1:
        print(f"Transfer disk {n} from {src} to {dest}")
        return
    TowerOfHanoi(n-1, src, auxi, dest)
    print(f"Transfer disk {n} from {src} to {dest}")
    TowerOfHanoi(n-1, auxi, dest, src)


TowerOfHanoi(3,"a", "c", "b")
