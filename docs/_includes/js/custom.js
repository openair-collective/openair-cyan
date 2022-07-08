async function switchScheme() {
  localStorage.getItem('theme') === 'dark' ? jtd.setTheme("openair") : jtd.setTheme("light");
}
window.onload = function(){
  switchScheme();
};
