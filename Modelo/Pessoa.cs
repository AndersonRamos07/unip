namespace pim_viii_aros
{
    public class Pessoa
    {
        protected int id { get; set;}
        private string nome {get; set;}
        private long cpf {get; set;}
        public Endereco endereco {get; set;}
        private List<Telefone> telefones {get; set;}
    }
}