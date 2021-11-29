namespace PIM_VIII.Models
{
    public class Pessoa
    {
        public int id {get; set;}
        public string Nome {get; set;}
        public long CPF {get; set;}
        public Endereco endereco {get; set;}
        public List<Telefone> telefones {get; set;}
    }
}