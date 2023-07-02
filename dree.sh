if [ "$1" = "-search" ]; then
    read -p "Enter Search Term: " SEARTERM
    script_dir="$(dirname "$0")"
    make run -C "$script_dir" ARGS="$(pwd) $SEARTERM 0"
else 
    script_dir="$(dirname "$0")"
    make run -C "$script_dir" ARGS="$(pwd) $1"
fi
