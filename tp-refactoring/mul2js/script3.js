
function mul2(n) {
    return n*2;
}

function make_handler(input, element) {
    return () => element.innerText = input.value*2;
}
