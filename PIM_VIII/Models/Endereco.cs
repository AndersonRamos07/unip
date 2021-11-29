using System.ComponentModel.DataAnnotations;

namespace PIM_VIII.Models
{
    public class Endereco
    {
        public int id {get; set;}
        [Required(ErrorMessage = "Favor informe o Logradouro.")]
        public string Logradouro {get; set;}
        [Required(ErrorMessage = "Informar o número, caso seja -Sem número- digitar S/N")]
        public string Numero {get; set;}
        [Required(ErrorMessage = "Favor informe o CEP.")]
        public int CEP {get; set;}
        [Required(ErrorMessage = "Favor informe o Bairro.")]
        public string Bairro {get; set;}
        [Required(ErrorMessage = "Favor informe a Cidade.")]
        public string Cidade {get; set;}
        [Required(ErrorMessage = "Favor informe o Estado.")]
        public string Estado {get; set;}
    }
}